/**
 * CS 383
 * Group #4
 * Created: 11/12/2016
 *
 * This file contains the implimentations of the RGB class used
 * to hold Red Green Blue values.
 */

#include "RGB.h"

/**
 * Default constructor initializes color to black
 */
RGB::RGB()
{
    this->red = 0;
    this->red = 0;
    this->red = 0;
}

/**
 * constructor that initializes color to passed in values
 * @param integer value representing amount of red
 * @param integer value representing amount of green
 * @param integer value representing amount of blue
 */
RGB::RGB(int red, int green, int blue)
{
    this->red = checkRange(red);
    this->red = checkRange(green);
    this->red = checkRange(blue);
}

/**
 * constructor that initializes color to a html hex value
 * @param a string value representing a 6 bit hexidecimal value
 */
RGB::RGB(std::string hex)
{
    // if incorrect format, return
    if (hex.length() != 6)
        return;
    
    this->red = checkRange(std::stoul(hex.substr(0,2), nullptr, 16));
    this->green = checkRange(std::stoul(hex.substr(2,2), nullptr, 16));
    this->blue = checkRange(std::stoul(hex.substr(4,2), nullptr, 16));
}

/**
 * constructor that converts Hue Saturation Lightness to RGB and creates object
 * @param an integer representing an angle of hue between 0 and 360
 * @param a float representing saturation, between 0 and 1
 * @param a float representing lightness, between 0 and 1
 */
RGB::RGB(int hue, float saturation, float lightness)
{
    int hueAngle =  std::abs(hue % 360);
    int saturationValue = std::abs(ceil(saturation)) - std::abs(saturation);
    int lightnessValue = std::abs(ceil(lightness)) - std::abs(lightness);
    
    float C = (1 - std::abs(2*lightnessValue - 1)) * saturationValue;
    float X = C * (1 - std::abs(((hueAngle / 60) % 2) - 1));
    float m = lightnessValue - (C / 2);
    
    if (hueAngle < 60) {
        this->red = (C+m)*255;
        this->green = (X+m)*255;
        this->blue = (0+m)*255;
    } else if (hueAngle < 120) {
        this->red = (X+m)*255;
        this->green = (C+m)*255;
        this->blue = (0+m)*255;
    } else if (hueAngle < 180) {
        this->red = (0+m)*255;
        this->green = (C+m)*255;
        this->blue = (X+m)*255;
    } else if (hueAngle < 240) {
        this->red = (0+m)*255;
        this->green = (X+m)*255;
        this->blue = (C+m)*255;
    } else if (hueAngle < 300) {
        this->red = (X+m)*255;
        this->green = (0+m)*255;
        this->blue = (C+m)*255;
    } else {
        this->red = (C+m)*255;
        this->green = (0+m)*255;
        this->blue = (X+m)*255;
    }
}

/**
 * Default destructor, empty for future use.
 */
RGB::~RGB()
{
}

/**
 * Returns an integer value representing the amount of red
 */
int RGB::getRed()
{
    return red;
}

/**
 * Sets the red component of the color
 * @param An int representing the amount of red
 */
void RGB::setRed(int red)
{
    this->red = checkRange(red);
}

/**
 * Returns an integer value representing the amount of green
 */
int RGB::getGreen()
{
    return green;
}

/**
 * Sets the green component of the color
 * @param An int representing the amount of green
 */
void RGB::setGreen(int green)
{
    this->green = checkRange(green);
}

/**
 * Returns an integer value representing the amount of blue
 */
int RGB::getBlue()
{
    return blue;
}

/**
 * Sets the blue component of the color
 * @param An int representing the amount of blue
 */
void RGB::setBlue(int blue)
{
    this->blue = checkRange(blue);
}

/**
 * Sets the color of the RGB class using 3 intigers
 * @param integer value representing amount of red
 * @param integer value representing amount of green
 * @param integer value representing amount of blue
 */
void RGB::setColor(int red, int green, int blue)
{
    this->red = checkRange(red);
    this->red = checkRange(green);
    this->red = checkRange(blue);
    
}

/**
 * Sets the color of the RGB class using a 
 * string representation of a hex value
 * @param a string value representing a 6 bit hexidecimal value
 */
void RGB::setColor(std::string hex)
{
    // if incorrect format, return
    if (hex.length() != 6)
        return;
    
    this->red = checkRange(std::stoul(hex.substr(0,2), nullptr, 16));
    this->green = checkRange(std::stoul(hex.substr(2,2), nullptr, 16));
    this->blue = checkRange(std::stoul(hex.substr(4,2), nullptr, 16));
}

/**
 * Converts Hue, Saturation, and Lightness to RGB and sets the color
 * @param An integer representing an angle of hue between 0 and 360
 * @param A float representing saturation, between 0 and 1
 * @param A float representing lightness, between 0 and 1
 */
void RGB::setColor(int hue, float saturation, float lightness)
{
    int hueAngle =  std::abs(hue % 360);
    int saturationValue = std::abs(ceil(saturation)) - std::abs(saturation);
    int lightnessValue = std::abs(ceil(lightness)) - std::abs(lightness);
    
    float C = (1 - std::abs(2*lightnessValue - 1)) * saturationValue;
    float X = C * (1 - std::abs(((hueAngle / 60) % 2) - 1));
    float m = lightnessValue - (C / 2);
    
    if (hueAngle < 60) {
        this->red = (C+m)*255;
        this->green = (X+m)*255;
        this->blue = (0+m)*255;
    } else if (hueAngle < 120) {
        this->red = (X+m)*255;
        this->green = (C+m)*255;
        this->blue = (0+m)*255;
    } else if (hueAngle < 180) {
        this->red = (0+m)*255;
        this->green = (C+m)*255;
        this->blue = (X+m)*255;
    } else if (hueAngle < 240) {
        this->red = (0+m)*255;
        this->green = (X+m)*255;
        this->blue = (C+m)*255;
    } else if (hueAngle < 300) {
        this->red = (X+m)*255;
        this->green = (0+m)*255;
        this->blue = (C+m)*255;
    } else {
        this->red = (C+m)*255;
        this->green = (0+m)*255;
        this->blue = (X+m)*255;
    }
}

/**
 * Converts the RGB class to a string suitable for output
 */
std::string RGB::toString()
{
    std::string cellString = "";
    
    cellString += std::to_string(red) + " ";
    cellString += std::to_string(green) + " ";
    cellString += std::to_string(blue);
    
    return cellString;
}

/**
 * Returns a color value in the range of 0 to 255
 */
int RGB::checkRange(int cValue)
{
    int value = std::abs((cValue % 255));
    return value;
}
