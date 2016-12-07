/**
 * CS 383
 * Group #4
 * Created: 11/07/2016
 *
 * This file contains the method definitions for the Cell class.
 */

// This class handles the the cell data structure which holds
// the color value for a single cell within a frame.

#ifndef CELL_H
#define CELL_H

#include "RGB.h"
#include <string>

/**
 * Class for storing RGB values for a single frame cell
 */
class Cell
{
public:
    Cell();
    Cell(RGB newColorValue);
    ~Cell();
    
    void setColor(RGB newColorValue);
    RGB getColor();
    std::string toString();
    
private:
    RGB colorValue;
};


#endif /* CELL_H */
