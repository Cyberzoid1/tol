#include "animation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

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
		//throw error
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
	int lineNum = 0;
	while (std::getline(tanfile, line))
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
		case recentColors2:
			break;
		case config:
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
