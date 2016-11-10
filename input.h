/**
* CS 383
* Group #4
* Created 11/09/2016
*
* This file provides the function stubs for reading data in from a .tan file.
*/
#ifndef INPUT_H
#define INPUT_H

#include "animation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> tokenize(std::string data);
int convertRgbInputStr(std::string str);
void handleLastColor(std::string data, Animation *animation);
void handleRecentColors(std::string data, Animation *animation);
void handleConfigInfo(std::string data, Animation *animation);
void readHeader(std::ifstream &tanfile, Animation *animation);
void handleRowOfCells(int rowNum, std::string data, Frame *frame, int width);
void readFrames(std::ifstream &tanfile, Animation *animation);
Animation readInAnimation(const char *filename);

#endif // !INPUT_H