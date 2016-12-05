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
    name= 0;
    height = 0;
    width = 0;
    isCurrent = false;
    grid = new QGridLayout();
    self = new QFrame();
}


frameElement::frameElement(const frameElement &obj)
{
    grid = new QGridLayout();
    grid = obj.grid;
    self = new QFrame();
    self = obj.self;
    isCurrent = obj.isCurrent;
    name = obj.name;
    width = obj.width;
    height = obj.height;
}


frameElement::~frameElement()
{
    //
}

frameElement::frameElement(int Name, int Height, int Width, bool Curr, QFrame * Self)
{
    name = Name;
    height = Height;
    width = Width;
    isCurrent = Curr;
    self = Self;
    grid = new QGridLayout();
}

void frameElement::handleCellColor(QPushButton *temp)
{
    temp->setStyleSheet("background-color: blue");
    return;
}

