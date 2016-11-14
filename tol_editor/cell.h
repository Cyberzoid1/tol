//  Created by Peter Fetros on 11/7/16.

// This class handles the the cell data structure which holds
// the color value for a single cell within a frame.

#ifndef CELL_H
#define CELL_H

#include "rgb.h"
#include <string>

class Cell {
public:
    Cell();
    ~Cell();
    void setColor(int red, int green, int blue);
    void setColor(rgb newColorValue);
    rgb Cell::getColor();
    std::string toString();
    
private:
    rgb colorValue;
};


#endif /* CELL_H */
