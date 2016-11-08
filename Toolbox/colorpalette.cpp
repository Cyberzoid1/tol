/* Matt and Domanic found this code in the source code for the
* Tower of Lights v2 project provided by Dr. Rinker. It will
* definitely be replaced after wednesday. Right now it is just
* a placeholder to show what such a class might actually look
* like. It is for mockup purposes only.
*
* Right now, the class gets its colors from hard coded
* values. This functionality will have to be broken up in order to
* save custom colors to the color palette.
*/

#include "colorpalette.h"

colorPalette::colorPalette()
{
  count = 15;
}

colorPalette::~colorPalette()
{

}

QString colorPalette::getColor()
{
  switch(count--){
    case 0:
      return "white";
    case 1:
      return "red";
    case 2:
      return "green";
    case 3:
      return "blue";
    case 4:
      return "cyan";
    case 5:
      return "magenta";
    case 6:
      return "yellow";
    case 7:
      return "gray";
    case 8:
      return "black";
    case 9:
      return "darkRed";
    case 10:
      return "darkGreen";
    case 11:
      return "darkBlue";
    case 12:
      return "darkCyan";
    case 13:
      return "darkMagenta";
    case 14:
      return "#808000"; //dark yellow
    case 15:
      return "darkGray";
    default:
      return "#888888";
    }
}


