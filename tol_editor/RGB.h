/**
 * CS 383
 * Group #4
 * Created: 11/12/2016
 *
 * This file contains the definitions of RGB class used
 * to hold Red Green Blue values.
 */

#ifndef RGB_h
#define RGB_h

#include <string>
#include <math.h>
#include <cmath>
#include <cstdlib>

class RGB {
public:
    RGB();
    RGB(int red, int green, int blue);
    RGB(std::string hex);
    RGB(int hue, float saturation, float lightness);
    ~RGB();
    
    int getRed();
    void setRed(int red);
    int getGreen();
    void setGreen(int green);
    int getBlue();
    void setBlue(int blue);
    
    void setColor(int red, int green, int blue);
    void setColor(std::string hex);
    void setColor(int hue, float saturation, float lightness);
    
    std::string toString();
    
private:
    int red;
    int green;
    int blue;
    
    static int checkRange(int cValue);
};


#endif /* RGB_h */
