/**
* @name Input
*/

#include "input.h"

/**
 * Parse the specified string by spaces and store in a vector.
 * @param data String object to be parsed
 * @return A STL Vector containing strings each comprised of a
 * single RGB value stored as a string
 */
std::vector<std::string> tokenize(std::string data) {
	std::istringstream buf(data);
	std::istream_iterator<std::string> beg(buf), end;

	std::vector<std::string> tokens(beg, end);
	return tokens;
}

/**
 * Use the specified data to set the RGB values of the Animation's last color.
 * @param data String object with RGB values.
 * @param animation A Pointer to an Animation object.
 */
void handleLastColor(std::string data, Animation *animation) {
	std::vector<std::string> rgbValues = tokenize(data);

	if (rgbValues.size() == 3) {
        animation->setLastColor(std::stoi(rgbValues[0]),
            std::stoi(rgbValues[1]),
            std::stoi(rgbValues[2]));
	} 
	else 
	{
		//throw error; will implement once ported into Qt framework
	}
}

/**
 * Parse the specified data to obtain the RGB values for the NUMCOLORS most recently
 * used colors in the Animation.
 * @param data String containing the RGB values.
 * @param animation A Pointer to an Animation object.
 * @return Void.
 */
void handleRecentColors(std::string data, Animation *animation) {
	std::vector<std::string> tokData = tokenize(data);
    RGB recentColors[NUMCOLORS];
    RGB tmp;
	///Since the colors are stored in RGB format, there should be 3 times
	///the total number of colors stored in the data
	if ((NUMCOLORS * 3) == tokData.size()) {
		int j = 0;
		for (int i = 0; i < tokData.size(); i += 3) {
            tmp.setColor(std::stoi(tokData[i]),
                         std::stoi(tokData[i+1]),
                         std::stoi(tokData[i+2]));
			recentColors[j++] = tmp;
		}
		animation->setRecentColors(recentColors);
	}
	else
	{
		//throw error; will implement once ported into Qt framework
	}
}
/**
 * Parse a String containing the configuration info from the specified data string.
 * @param data String with the configuration info.
 * @param animation A pointer to an Animation object.
 * @return Void.
 */
void handleConfigInfo(std::string data, Animation *animation) {
	std::vector<std::string> tokData = tokenize(data);

	if (tokData.size() == 3) {
		//ignore tokData[0] as the number of frames will be calculated once
		//the list of frames is populated
		animation->setHeight(std::stoi(tokData[1]));
		animation->setWidth(std::stoi(tokData[2]));
	}
	else
	{
		//throw error; will implement once ported into Qt framework
	}
}
/**
 * Read in and parse the Animation's header info from the specified file.
 * @param tanfile A Reference to an ifstream object pointing
 * to the .tan2 file.
 * @param animation A Pointer to an Animation object.
 * @return Void.
 */
void readHeader(std::ifstream &tanfile, Animation *animation) {
	enum lines
	{
        version, file, lastColor, recentColors, config
	};
	std::string line;
	std::string recColors = "";
	int lineNum = 0;
    while (lineNum < 5 && std::getline(tanfile, line))
	{
		switch (lineNum++)
		{
		case version:
			animation->setVersion(line);
			break;
		case file:
			animation->setFilename(line);
			break;
		case lastColor:
			handleLastColor(line, animation);
			break;
        case recentColors:
            handleRecentColors(line, animation);
			break;
		case config:
			handleConfigInfo(line, animation);
			break;
		default:
			break;
		}
	}
}
/**
 * Looks ahead in the file to the first line of cell values. Then tokenizes that line
 * to determine the number of values and divides that by 3 to account for the RGB triples
 * in order to find the number of cells in each row.
 * @note This function should only be called after reading the .tan2 file header and
 * just before reading in the frames.
 * @param tanfile A reference to an ifstream object pointing
 * to the .tan2 file.
 * @return {int} Width of the frames stored in the file.
 */
int getActualWidth(std::ifstream &tanfile) {
    if (tanfile.good()){
        //store the current position of the file for resetting later
        std::streampos startPos = tanfile.tellg();
        std::string line;
        //skip first line; it contains the frame's start time
        std::getline(tanfile,line);
        //this line contains the first row of cells
        std::getline(tanfile, line);
        std::vector<std::string> cells = tokenize(line);

        //reset the file position to where it was at the start of the call
        tanfile.seekg(startPos);

        //divide the size by 3 to account for the RGB triples
        return (int)(cells.size()/3);
    }
    return -1;
}
/**
 * Looks ahead in the file to determine the actual height of the frame in a .tan2  file. Then
 * counts the number of rows before the line containing the next frame's start time in order
 * to determine the number of rows in a column.
 * @note This function should only be called after reading the .tan2  file header and
 * just before reading in the frames.
 * @param tanfile A reference to an ifstream object pointing
 * to the .tan2 file.
 * @return Integer value representing the number of rows in a .tan2 file
 */
int getActualHeight(std::ifstream &tanfile){
    if (tanfile.good()){
        //store the current position of the file for resetting later
        std::streampos startPos = tanfile.tellg();
        std::string line;
        int actualHeight = 0;

        //skip first line; it contains the frame's start time
        std::getline(tanfile, line);
        //this next line is the first row of cells in the frame; start with it
        std::getline(tanfile, line);
        //If the tokenized line contains more than one item, then it is another
        //row of cells and should be counted into the frame's actualHeight.
        //If the tokenized line only contains less than one item, then it is the start time
        //for the next frame or the end of file and the count should be stopped.
        while(tokenize(line).size() > 1){
            actualHeight++;
            std::getline(tanfile, line);
        }

        //if the animation file only had one frame, then it will have reached the eof
        //if so, clear the eof bit and set it back to the original position from the start of the file
        if(tanfile.eof()){
            tanfile.clear();
            tanfile.seekg(startPos, std::ios_base::beg);
        }
        //if not, simply reset to the original position
        else
            tanfile.seekg(startPos);

        return actualHeight;
    }
    return -1;
}

/**
 * Parse the RGB values for a row of cells from the specified data and
 * set the corresponding cell colors in the frame.
 * @param rowNum Index of the current row in the Frame.
 * @param data String object containing the cell values.
 * @param frame A Pointer to a frame object.
 * @param width Width of the frame in cell objects.
 * @return Void.
 */
void handleRowOfCells(int rowNum, std::string data, Frame *frame, int width) {
	std::vector<std::string> cellValues = tokenize(data);
    RGB tmp;
	//since the cell values are stored in RGB triples, there should be 3*width of the animation
    if (cellValues.size() == width*3) {
		int colNum = 0;
        for (int i = 0; i < cellValues.size(); i += 3) {
            tmp.setColor(std::stoi(cellValues[i]),
                         std::stoi(cellValues[i+1]),
                         std::stoi(cellValues[i+2]));
            frame->setCellColor(colNum++, rowNum, tmp);
		}
	}
	else {
		//throw error; will implement once ported into Qt framework
	}
}
/**
 * Read in the frames from the tanfile and store them in the Animation's list.
 * @note This function picks up in the file where readHeader ended.
 * @note Due to the pre-existing format of the .tan2 file and its
     * storage of the incorrect height and width of a frame in its config info,
     * it is necessary to programmatically determine those values through reading the file.
     * This is relatively costly since it involves multiple file I/O operations, but is necessary
     * in order to be backwards-compatible with existing infrastructure.
 * @param tanfile A Reference to an ifstream object pointing
 * to the .tan2 file.
 * @param animation A Pointer to the Animation
 */
void readFrames(std::ifstream &tanfile, Animation *animation){
    /*
     * Note: Due to the pre-existing format of the .tan2 file and its
     * storage of the incorrect height and width of a frame in its config info,
     * it is necessary to programmatically determine those values through reading the file.
     * This is relatively costly since it involves multiple file I/O operations, but is necessary
     * in order to be backwards-compatible with existing infrastructure.
     */
    animation->setWidth(getActualWidth(tanfile));
    animation->setHeight(getActualHeight(tanfile));
    Frame frame(animation->getWidth(), animation->getHeight());

    std::string line;
	std::list<Frame> frames;
	int pos = 0;
	while (std::getline(tanfile, line))
	{
		//the first line contains the time stamp
        frame.setStartTime(std::stoi(line));
		//now read as many lines as are specified by the animation's height
		//each line corresponds to a row in the animation
		for (int i = 0; i < animation->getHeight(); i++)
		{
			line = "";
			std::getline(tanfile, line);
			handleRowOfCells(i, line, &frame, animation->getWidth());
		}
		//now that all of the data has been collected for a single frame
		//handle that data and add it to the list of frames
		frame.setFrameNumber(pos++);
		frames.push_back(frame);
	}
	animation->setFrames(frames);
}
/**
 * Read in an Animation from the specified file location/name.
 * @param a filename or filepath to read from.
 * @return A reference to an Animation object.
 */
Animation* readInAnimation(const char *filename) {
    Animation *animation = new Animation;

	std::ifstream tanfile;
	tanfile.open(filename);
    if (tanfile.good()){
        readHeader(tanfile, animation);
        readFrames(tanfile, animation);
    }
	tanfile.close();

	return animation;
}
