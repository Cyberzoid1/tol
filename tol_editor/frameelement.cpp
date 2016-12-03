/**
  * @class frameElement
  */


#include "frameelement.h"


/**
 * @brief cell::setColor
 * @param r
 * @param g
 * @param b
 * This sets the RGB values of the cells
 */


void cell::setColor( int r, int g, int b )
{
    cell::red = r;
    cell::green = g;
    cell::blue = b;
}

void cell::setCell( QPushButton* button )
{
    cell::self = button;
}

frameElement::frameElement()
{
    width = 8;
    height = 20;
    isCurrent = false;
    grid = new QGridLayout;
}


