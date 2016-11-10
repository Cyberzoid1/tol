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
 * Convert the specified string to an int and then ensure that it is between 0-255.
 * @param str string containing an integer
 */
int convertRgbInputStr(std::string str) {
	int val = std::stoi(str);
	return ((val >= 0 && val <= 255) ? val : 0);
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
	rgb recentColors[NUMCOLORS];
	rgb tmp;
	///Since the colors are stored in RGB format, there should be 3 times
	///the total number of colors stored in the data
	if ((NUMCOLORS * 3) == tokData.size()) {
		int j = 0;
		for (int i = 0; i < tokData.size(); i += 3) {
			tmp.red = convertRgbInputStr(tokData[i]);
			tmp.green = convertRgbInputStr(tokData[i + 1]);
			tmp.blue = convertRgbInputStr(tokData[i + 2]);
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
		version, file, lastColor, recentColors1, recentColors2, config
	};
	std::string line;
	std::string recColors = "";
	int lineNum = 0;
	while (lineNum < 6 && std::getline(tanfile, line))
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
		case recentColors1:
			///simply store the first line of recent colors to be handled once
			///the next line is read in
			recColors = line + " ";
			break;
		case recentColors2:
			///add on the second line of recent colors and then handle it all together
			recColors += line;
			handleRecentColors(recColors, animation);
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
 * Read in an Animation from the specified file.
 * @param filename
 */
Animation readInAnimation(const char *filename) {
	Animation animation;

	std::ifstream tanfile;
	tanfile.open(filename);
	readHeader(tanfile, &animation);
	tanfile.close();

	return animation;
}
