//
//  frame.cpp
//  TOL_TEST
//
//  Created by Peter Fetros on 11/7/16.
//  Copyright © 2016 Peter Fetros. All rights reserved.
//

#include "frame.h"

// Initialize an empty frame.
Frame::Frame() {
    frameNumber = 0;
    startTime = 0;
}

// Initialize a frame with width by height number of blank cells.
Frame::Frame(int width, int height) {
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

// Initialize a frame using another frame.
Frame::Frame(Frame* newFrame) {
    frameNumber = 0;
    startTime = 0;
    std::copy(newFrame->cells.begin(), newFrame->cells.end(), std::back_inserter(cells));
}

// No memory to destroy
Frame::~Frame() {
    
}

// Set color at position x,y using seperate int's for reg, green, and blue.
void Frame::setCellColor(int x, int y, int red, int green, int blue) {
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return;
    
    int validRed = (red <= 255 && red >= 0) ? red : 0;
    int validGreen = (green <= 255 && green >= 0) ? green : 0;
    int validBlue = (blue <= 255 && blue >= 0) ? blue : 0;
    
    cells[y-1][x-1].setColor(validRed, validGreen, validBlue);
}

// Set color at position x,y using rgb struct.
void Frame::setCellColor(int x, int y, rgb color) {
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return;
    
    cells[y-1][x-1].setColor(color);
}

// get color for a cell.
rgb Frame::getCellColor(int x, int y) {
    if (y > cells.size() || y < 0 || x > cells[y].size() || x < 0)
        return rgb();
    
    return cells[y-1][x-1].getColor();
}

// get the frame number
int Frame::getFrameNumber() {
    return frameNumber;
}

// set the frame number
void Frame::setFrameNumber(int number) {
    frameNumber = number;
}

// get the frame start time
int Frame::getStartTime() {
    return startTime;
}

// set the frame start time
void Frame::setStartTime(int time) {
    startTime = time;
}


// Serialize the frame into string format suitable for tan file ouput.
std::string Frame::toString() {
    std::string frameString = "";
    
    for(auto columnIt = cells.begin(); columnIt != cells.end(); ++columnIt) {
        
        std::vector<Cell> cellRow = *columnIt;
        for(auto rowIt = cellRow.begin(); rowIt != cellRow.end(); ++rowIt) {
            
            frameString += rowIt->toString() + " ";
        }
        frameString += "\n";
    }
    
    return frameString;
}