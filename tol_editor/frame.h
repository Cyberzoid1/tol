//  Created by Peter Fetros on 11/7/16.


#ifndef FRAME_H
#define FRAME_H

#include "Cell.h"
#include <string>
#include <vector>
#include <iterator>

class Frame {
public:
    Frame();
    Frame(int width, int height);
    Frame(Frame* newFrame);
    ~Frame();
    
    int getFrameNumber();
    void setFrameNumber(int number);
    int getStartTime();
    void setStartTime(int time);
    
    void setCellColor(int x, int y, int red, int green, int blue);
    void setCellColor(int x, int y, rgb color);
    rgb getCellColor(int x, int y);

    std::string toString();
    
private:
    std::vector<std::vector<Cell>> cells;
    int frameNumber;
    int startTime;
};


#endif /* FRAME_H */
