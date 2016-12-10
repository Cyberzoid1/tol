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
    
    return cells[y][x].getColor();
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
 * Shift the rows of the frame up, inserting a blank row at the bottom.
 * @param width number of columns
 * @param height number of rows
 * @return Void.
 */
void Frame::shiftUp(int width, int height)
{
    RGB black;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (row+1 < height)
                cells[row][column] = cells[row+1][column];
            else
                cells[row][column] = Cell(black);
        }
    }
}
/**
 * Shift the rows of the frame down, inserting a blank row at the top.
 * @param width number of columns
 * @param height number of rows
 * @return Void.
 */
void Frame::shiftDown(int width, int height)
{
    RGB black;
    for (int row = height - 1; row >= 0; row--) {
        for (int column = width - 1; column >= 0; column--) {
            if (row-1 < 0)
                cells[row][column] = Cell(black);
            else
                cells[row][column] = cells[row-1][column];
        }
    }
}
/**
 * Shift the columns of the frame left, inserting a blank column at the far right.
 * @param width number of columns
 * @param height number of rows
 * @return Void.
 */
void Frame::shiftLeft(int width, int height)
{
    RGB black;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (column+1 < width)
                cells[row][column] = cells[row][column+1];
            else
                cells[row][column] = Cell(black);
        }
    }
}
/**
 * Shift the columns of the frame right, inserting a blank column at the far left.
 * @param width number of columns
 * @param height number of rows
 * @return Void.
 */
void Frame::shiftRight(int width, int height)
{
    RGB black;
    for (int row = height - 1; row >= 0; row--) {
        for (int column = width - 1; column >= 0; column--) {
            if (column-1 < 0)
                cells[row][column] = Cell(black);
            else
                cells[row][column] = cells[row][column-1];
        }
    }
}
/**
 * Serialize the frame into a string object representing this
 * frame which is suitable for output into a .tan2 file
 * @return A string object starting with the startTime followed by
 * triples representing the color of every cell in the animation.
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
