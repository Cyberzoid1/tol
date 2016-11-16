/**
 * CS 383
 * Group #4
 * Created 11/08/2016
 *
 * This file provides the function definitions for reading data in from a .tan file.
 */
#include "input.h"

/**
 * Parse the specified string by spaces and store in a vector.
 * @param data string to be parsed
 */
std::vector<std::string> tokenize(std::string data) {
	std::istringstream buf(data);
	std::istream_iterator<std::string> beg(buf), end;

	std::vector<std::string> tokens(beg, end);
	return tokens;
}
/**
 * Use the specified data to set the RGB values of the Animation's last color.
 * @param data string with values
 * @param animation pointer to the Animation object
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
 * @param data string with the values
 * @param animation pointer to the Animation object
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
 * Parse the config info from the specified data string.
 * @param data string with the info
 * @param animation pointer to the Animation object
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
 * Read in the Animation's header info from the specified file.
 * @param tanfile file reference
 * @param animation pointer to the Animation object
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
 * Parse the RGB values for a row of cells from the specified data and
 * set the corresponding cell colors in the frame.
 * @param rowNum index of the current row in the Frame
 * @param data string containing the cell values
 * @param frame pointer to frame
 * @param width of the frame
 */
void handleRowOfCells(int rowNum, std::string data, Frame *frame, int width) {
	std::vector<std::string> cellValues = tokenize(data);
    RGB tmp;
    //TODO: adjust to handle .tan2 format ((3*width)+context cells)
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
 * Note: this function picks up in the file where readHeader ended.
 * @param tanfile file containing the animation data
 * @param animation pointer to the Animation
 */
void readFrames(std::ifstream &tanfile, Animation *animation){
	std::string line;
	Frame frame(animation->getWidth(), animation->getHeight());
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
 * Read in an Animation from the specified file.
 * @param filename
 */
Animation readInAnimation(const char *filename) {
	Animation animation;

	std::ifstream tanfile;
	tanfile.open(filename);
	readHeader(tanfile, &animation);
	readFrames(tanfile, &animation);
	tanfile.close();

	return animation;
}
