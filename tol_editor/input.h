/**
* @author Trevor Morse
* @date 11/09/2016
* @name Input
* @brief This is the header file that defines the file reading functionality.
* @details This header file defines the different functions that are used
* during the process of reading an animations .tan2 file into the Tower Lights
* animator and then extracting the information and translating it into the proper
* data structures and objects
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
void handleLastColor(std::string data, Animation *animation);
void handleRecentColors(std::string data, Animation *animation);
void handleConfigInfo(std::string data, Animation *animation);
void readHeader(std::ifstream &tanfile, Animation *animation);
int getActualWidth(std::ifstream &tanfile);
int getActualHeight(std::ifstream &tanfile);
void handleRowOfCells(int rowNum, std::string data, Frame *frame, int width);
void readFrames(std::ifstream &tanfile, Animation *animation);
Animation* readInAnimation(const char *filename);

#endif // !INPUT_H
