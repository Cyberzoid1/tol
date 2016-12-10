/**
 * @author Peter Fetros
 * @date 11/07/2016
 * @class Cell
 * @brief This is the header file for the Cell class.
 * @details This class handles the cell data such as color
 * values related to the cells of an animations frames as well
 * as the various functions and methods usd to set a cells color
 * values
 */

#ifndef CELL_H
#define CELL_H

#include "RGB.h"
#include <string>

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
    RGB colorValue; //!< An RGB object used to contain the color data relevant to this cell
};


#endif /* CELL_H */
