/**
 * CS 383
 * Group #4
 * Created: 11/07/2016
 *
 * This file contains the method definitions for the Frame class.
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

    std::string toString();
    
private:
    std::vector<std::vector<Cell>> cells;
    int frameNumber;
    int startTime;
};


#endif /* FRAME_H */
