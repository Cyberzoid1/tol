/**
* @author Peter Fetros
* @date 11/12/2016
* @class RGB
* @brief This is the header file that defines the RGB class.
* @details This header file defines the class used to contain the color data
* used by the cells to determine what color they will be during an animation.
* It also contains several methods for converting different color representations
* into the RGB color format.
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
    int red; //!< An integer between 0 and 255 representing the red component of the color
    int green; //!< An integer between 0 and 255 representing the green component of the color
    int blue; //!< An integer between 0 and 255 representing the blue component of the color
    
    static int checkRange(int cValue);
};


#endif /* RGB_h */
