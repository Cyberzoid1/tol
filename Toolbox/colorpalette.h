/*! \file colorpalette.h
 * \brief This file defines the code side of the colorPalette class.
 * It stores information about default colors.
 */

#ifndef COLORPALETTE_H
#define COLORPALETTE_H

#include <QObject>
#include <QString>

/*!
 * \brief The colorPalette class
 */

/*!
 * This class serves as a helper class to the Color Palette QML code.
 * It keeps track of which color is currently being
 * produced and return a color in accordence.
 *
 * Matt and Domanic found this code in the source code for the
 * Tower of Lights v2 project provided by Dr. Rinker. It will
 * definitely be replaced after wednesday. Right now it is just
 * a placeholder to show what such a class might actually look
 * like. This is for mockup purposes only.
 *
 * Right now, the class gets its colors from hard coded
 * values. This functionality will have to be broken up in order to
 * save custom colors to the color palette.
 */

class colorPalette : public QObject
{
  Q_OBJECT
public:
    colorPalette();
    ~colorPalette();
    Q_INVOKABLE QString getColor();

private:
    int count; /*!< keeps track of the current color */
};

#endif // COLORPALETTE_H
