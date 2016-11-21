/**
* @class Cell
*/

#include "cell.h"

/**
 * Initialize a cell with the defualt color black
 */
Cell::Cell()
{
    colorValue = RGB();
}

/**
 * Initialize a cell with an rgb structure
 * @param Color of the cell contained in an rgb struct
 */
Cell::Cell(RGB newColorValue)
{
    colorValue = newColorValue;
}

/**
 * Destructor empty for now
 */
Cell::~Cell()
{
}

/**
 * Sets the color of the cell using an rgb struct
 * @param Color of the cell contained in an rgb struct
 */
void Cell::setColor(RGB newColorValue)
{
    colorValue = newColorValue;
}

/**
 * Returns the color of this cell as an rgb struct
 */
RGB Cell::getColor()
{
    return colorValue;
}

/**
 * Serializes this class as a string suitable for output as part of a .tan file
 */
std::string Cell::toString()
{
    return colorValue.toString();
}
