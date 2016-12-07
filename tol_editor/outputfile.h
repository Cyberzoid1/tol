/**
 * CS 383
 * Group #4
 * Created: 11/08/2016
 *
 * This file defines the function defintions for outputting a tan file
 */

#ifndef outputfile_h
#define outputfile_h

#include <string>
#include <algorithm>
#include <fstream>

#include "animation.h"

/**
 * Header for functions relating to writing out  tan file
 */

int writeFile(std::string rawFileName, Animation* animation);

std::string formatFileName(std::string rawFileName);
std::string getErrorString(int errorCode);

#endif /* outputfile_h */
