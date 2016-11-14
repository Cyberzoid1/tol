//  Created by Peter Fetros on 11/7/16.

// This class handles the the cell data structure which holds
// the color value for a single cell within a frame.

#ifndef CELL_H
#define CELL_H

#include "rgb.h"

class Cell {
public:
    Cell();
    ~Cell();
    void setColor(int red, int green, int blue);
    void setColor(rgb newColorValue);
    std::string toString();
    
private:
    rbg colorValue;
};


#endif /* CELL_H */
