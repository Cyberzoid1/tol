/**
* @class Frame
*/

#include "frame.h"

/**
 * Initializes an empty frame object with the default
 * values; FrameNumber: 0, and startTime = 0.
 */
Frame::Frame()
{
    frameNumber = 0;
    startTime = 0;
}

/**
 * Initialize a frame object by specifying the frames
 * width in cell objects followed by its height in cell objects.
 * @param width Width of the frame (number of cells in a row)
 * @param height Height of the frame (number of rows in a column)
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
 * @param newFrame Reference to a pre-exisitng frame
 */
Frame::Frame(Frame* newFrame)
{
    frameNumber = 0;
    startTime = 0;
    std::copy(newFrame->cells.begin(), newFrame->cells.end(), std::back_inserter(cells));
}

/**
 * Default destructor, no memory to clean up so empty for
 * now.
 */
Frame::~Frame()
{
}

/**
 * Set the color of a Cell at a position by passing in an
 * x and y coordinate along with an RGB object containing
 * the color to make the cell.
 * @param x Index of the selected row position in the frame.
 * @param y Index of the selected column position in the frame.
 * @param color RGB class holding the color data for the cell.
 * @return Void.
 */
void Frame::setCellColor(int x, int y, RGB color)
{
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return;
    
    cells[y][x].setColor(color);
}


/**
 * get the color of a cell using it's x and y position inside the frame.
 * @param x Index of the selected row position in the frame.
 * @param y Index of the selected column position in the frame.
 * @return An RGB object containing the color of the specified cell.
 */
RGB Frame::getCellColor(int x, int y)
{
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return RGB();
    
    return cells[y-1][x-1].getColor();
}

/**
 * Get the number representing the frames position in the
 * animation in relation to the first frame.
 * @return An integer representing this frames position.
 */
int Frame::getFrameNumber()
{
    return frameNumber;
}

/**
 * Set the number representing the frames position in the
 * animation in relation to the first frame.
 * @param number An integer representing this frames position.
 * @return Void.
 */
void Frame::setFrameNumber(int number)
{
    frameNumber = number;
}

/**
 * Get the frame's start time in milliseconds.
 * @return An Integer representing the time to show this
 * frame during the animation, in milliseconds.
 */
int Frame::getStartTime()
{
    return startTime;
}

/**
 * Set the frame's start time in milliseconds.
 * @param time An Integer representing the time to show this
 * frame during the animation, in milliseconds.
 * @return Void.
 */
void Frame::setStartTime(int time)
{
    startTime = time;
}


/**
 * Serialize the frame into a string object representing this
 * frame which is suitable for output into a .tan2 file
 * @return A string object starting with the startTime followed by
 * triples representing the color of every cell in the animation.
 */
std::string Frame::toString()
{
    std::string frameString = std::to_string(startTime);
    
    for(auto columnIt = cells.begin(); columnIt != cells.end(); ++columnIt) {
        
        std::vector<Cell> cellRow = *columnIt;
        for (auto rowIt = cellRow.begin(); rowIt != cellRow.end(); ++rowIt) {
            frameString += rowIt->toString() + " ";
        }
        frameString += "\n";
    }
    
    return frameString;
}
