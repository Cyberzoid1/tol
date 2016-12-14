/**
 * @author Peter Fetros
 * @date 11/08/2016
 * @name Input
 * @brief This is the header file that defines the file output functionality.
 * @details This header file defines the different functions that are used
 * during the process of writing an animations into a .tan2 file. It also defines
 * several helper functions that are used for determinding proper filename and paths
 * as well a function for getting a string representation of any errors returned by the
 * file writing process.
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
