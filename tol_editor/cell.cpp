//
//  cell.cpp
//
//  Created by Peter Fetros on 11/7/16.
//  Copyright © 2016 Peter Fetros. All rights reserved.
//

#include "cell.h"

Cell::Cell() {
    colorValue.red = 0;
    colorValue.green = 0;
    colorValue.blue = 0;
}

Cell::~Cell() {
}

void Cell::setColor(int red, int green, int blue) {
    colorValue.red = red;
    colorValue.green = green;
    colorValue.blue = blue;
}

void Cell::setColor(rgb newColorValue) {
    colorValue = newColorValue;
}

rgb Cell::getColor() {
    return colorValue;
}

std::string Cell::toString() {
    std::string cellString = "";
    
    cellString += std::to_string(colorValue.red) + " ";
    cellString += std::to_string(colorValue.green) + " ";
    cellString += std::to_string(colorValue.blue);
    
    return cellString;
}