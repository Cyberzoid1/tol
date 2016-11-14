/**
 * CS 383
 * Group #4
 * Created: 11/08/2016
 *
 * This file contains the methods for writing out a .tan file
 */

#include "outputfile.h"

/**
 * Check the filename for extenstion and add it if not present
 * @param The raw file name string passed into writefile
 */
std::string formatFileName(std::string rawFileName) {
    std::string lowerName = rawFileName;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    
    if (lowerName.find(".tan",lowerName.size()-4) == std::string::npos)
        return (rawFileName + ".tan");
    else
        return rawFileName;
}

/**
 * Write the animation to a specified file location.
 * @param The file name or path where the file should be written
 * @param animation pointer to the Animation object
 */
int writeFile(std::string rawFileName, Animation* animation) {
    
    if (rawFileName.size() == 0) {
        return -1;
    }
    if (animation == NULL) {
        return -2;
    }
    
    std::string fileName = formatFileName(rawFileName);
    
    std::ofstream outFile (fileName);
    if (outFile.good()) {
        outFile << animation->toString();
        outFile.close();
    }
    else {
        return -3;
    }
    
    return 0;
}

/**
 * returns a string representation of the error, if it exists,
 * returned by the writeFile function
 * @param Integer Error number returned by the writeFile function
 */
std::string getErrorString(int errorCode) {
    switch (errorCode) {
        case 0:
            return "No Error.";
        case -1:
            return "Empty string specified as file name.";
        case -2:
            return "NULL Animation object passed into function";
        case -3:
            return "Could not open file for writing purposes.";
        default:
            return "Unrecognized Error Code!";
    }
}
