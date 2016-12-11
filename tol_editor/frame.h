/**
 * @author Peter Fetros
 * @date 11/07/2016
 * @class Frame
 * @brief This is the header file for the Frame class.
 * @details This class contains all of the information for a single
 * frame of an animation. Objects of this class are comprised of a
 * 2Dimensional array of cell objects that make up the frames color parts.
 * This class is also used to interact with the different cells, for example setting
 * cell colors.
 */

#ifndef FRAME_H
#define FRAME_H

#include "Cell.h"
#include <string>
#include <vector>
#include <iterator>

/**
 * Class for storing all cells and represents a single
 * frame of the animation
 */
class Frame
{
public:
    Frame();
    Frame(int width, int height);
    Frame(Frame* newFrame);
    ~Frame();
    
    int getFrameNumber();
    void setFrameNumber(int number);
    int getStartTime();
    void setStartTime(int time);
    
    void setCellColor(int x, int y, RGB color);
    RGB getCellColor(int x, int y);

    void shiftUp(int width, int height);
    void shiftDown(int width, int height);
    void shiftLeft(int width, int height);
    void shiftRight(int width, int height);

    std::string toString();
    
private:
    std::vector<std::vector<Cell>> cells; //!< 2-Dimenstional Vector of cell objects making up the pixles of the frame
    int frameNumber; //!< This framse index location within the complete animation
    int startTime; //!< The time in milliseconds that this frame will be played during the Animation
};


#endif /* FRAME_H */
