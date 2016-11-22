/**
* @name Output
*/

#include "outputfile.h"

/**
 * Check the filename for extenstion and add it if not present.
 * @param rawFileName The raw file name string passed into writefile.
 * @return A string object containing the properly formatted filepath, including file extension.
 */
std::string formatFileName(std::string rawFileName)
{
    std::string lowerName = rawFileName;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    std::string fileType = ".tan2";
    if (lowerName.find(fileType,lowerName.size()-fileType.size()) == std::string::npos)
        return (rawFileName + ".tan2");
    else
        return rawFileName;
}

/**
 * Write the animation to a specified file location.
 * @param rawFileName The file name or path where the file should be written
 * @param animation A pointer to the Animation object
 */
int writeFile(std::string rawFileName, Animation* animation)
{
    
    if (rawFileName.size() == 0)
        return -1;

    if (animation == NULL)
        return -2;
    
    std::string fileName = formatFileName(rawFileName);
    
    std::ofstream outFile (fileName);
    if (outFile.good()) {
        outFile << animation->toString();
        outFile.close();
    }
    else
        return -3;
    
    return 0;
}

/**
 * returns a string representation of the error, if it exists,
 * returned by the writeFile function.
 * @param errorCode An Integer representing the error number returned by the writeFile function.
 * @return A string object containing a description of the error that occured.
 */
std::string getErrorString(int errorCode)
{
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
