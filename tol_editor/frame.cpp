/**
 * CS 383
 * Group #4
 * Created: 11/07/2016
 *
 * This file contains the implimentation details of the Frame class defined in
 * frame.h
 */
#include "frame.h"

/**
 * initializes an empty Frame object.
 */
Frame::Frame()
{
    frameNumber = 0;
    startTime = 0;
}

/**
 * Initialize a frame with a specific width and height.
 * @param width of the frame (number of cells in a row)
 * @param height of the frame (number of rows in a frame)
 */
Frame::Frame(int width, int height)
{
    frameNumber = 0;
    startTime = 0;
    for (int row = 0; row < height; row++) {
        std::vector<Cell> cellRow;
        for (int column = 0; column < width; column++) {
            cellRow.push_back(Cell());
        }
        cells.push_back(cellRow);
    }
}

/**
 * Initialize a frame as a copy of another frame
 * @param reference to a pre-exisitng frame
 */
Frame::Frame(Frame* newFrame)
{
    frameNumber = 0;
    startTime = 0;
    std::copy(newFrame->cells.begin(), newFrame->cells.end(), std::back_inserter(cells));
}

/**
 * Placeholder for a destructor if needed in the future
 */
Frame::~Frame()
{
}

/**
 * Set the color of a Cell at a x,y positon using seperate ints
 * for the red, green, blue values
 * @param Column position in the row of the frame
 * @param Row position in the frame
 * @param RGB class holding the color data for the cell
 */
void Frame::setCellColor(int x, int y, RGB color)
{
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return;
    
    cells[y][x].setColor(color);
}


/**
 * get the color of a cell using it's coordinates inside the frame
 * @param Column position in the row of the frame
 * @param Row position in the frame
 */
RGB Frame::getCellColor(int x, int y)
{
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return RGB();
    
    return cells[y][x].getColor();
}

/**
 * get the number of a frame
 */
int Frame::getFrameNumber()
{
    return frameNumber;
}

/**
 * set the number of a frame
 * @param Int representing frame number
 */
void Frame::setFrameNumber(int number)
{
    frameNumber = number;
}

/**
 * get the frame start time
 */
int Frame::getStartTime()
{
    return startTime;
}

/**
 * set the frame start time
 * @param Int representing the frame start time
 */
void Frame::setStartTime(int time)
{
    startTime = time;
}


/**
 * Serialize the frame into string format suitable for tan file ouput.
 */
std::string Frame::toString()
{
    std::string frameString = std::to_string(startTime) + "\n";

    
    for(auto columnIt = cells.begin(); columnIt != cells.end(); ++columnIt) {
        
        std::vector<Cell> cellRow = *columnIt;
        for (auto rowIt = cellRow.begin(); rowIt != cellRow.end(); ++rowIt) {
            frameString += rowIt->toString() + " ";
        }
        frameString += "\n";
    }
    
    return frameString;
}
