/**
 * @class Cell
 */

#include "cell.h"

/**
 * Initialize a cell with the defualt RGB object color
 * black.
 */
Cell::Cell()
{
    colorValue = RGB();
}

/**
 * Initialize a cell with a pre-existing RGB object.
 * @param newColorValue An RGB object containing the
 * color to set the cell to.
 */
Cell::Cell(RGB newColorValue)
{
    colorValue = newColorValue;
}

/**
 * Default destructor, no memory to clean up so empty for
 * now.
 */
Cell::~Cell()
{
}

/**
 * Sets the color of a cell using the color stored inside
 * an RGB object.
 * @param newColorValue An RGB object containing the
 * color to set the cell to.
 * @return Void.
 */
void Cell::setColor(RGB newColorValue)
{
    colorValue = newColorValue;
}

/**
 * Returns a copy of the RGB object that contains
 * this cell's color.
 * @return An RGB object.
 */
RGB Cell::getColor()
{
    return colorValue;
}

/**
 * Serializes this class by returing a string object
 * containing the RGB color as a 3 integer tuple.
 * @return A string containing 3 integers representing
 * red, green, blue in that order.
 */
std::string Cell::toString()
{
    return colorValue.toString();
}
