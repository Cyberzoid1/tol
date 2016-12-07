/**
* @author Zachary Spence
* @date 11/28/2016
* @class frameElement
* @brief This is the header file for the frameElement class.
* @details This class is utilized to setup the the nodes in the list
* listFrames, which holds the UI frames and associated data. Each node
* holds a reference to the particular frame, particular grid, a height,
* a width, a numeric name, and a grid of cells
*/




#ifndef FRAMEELEMENT_H
#define FRAMEELEMENT_H

#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>


class cell
{
    int red;                                    //!< A number to hold red values
    int green;                                  //!< A number to hold green values
    int blue;                                   //!< A number to hold blue values
    QPushButton* self;                          //!< A pointer to the QPushButton the cell refers to
public:
    void setColor( int r, int g, int b );
    void setCell( QPushButton* button );


};


class frameElement                             // nodes for the list of ui frames
{
public:
    QFrame* self;                               //!< A pointer to the UI frame belonging to the node
    QGridLayout *grid;                          //!< A pointer to the grid layout of the node
    bool isCurrent;                             //!< A boolean to hold whether the node is the current frame being viewed
    int name;                                   //!< A name, which is the number identifying the frame
    int width;                                  //!< A number holding the width of the frame
    int height;                                 //!< A number holding the height of the frame


public slots:
    //void colorChangedHandler();

public:
    frameElement();
    frameElement( int n, int h, int w, bool isCurr );
    ~frameElement();
};

#endif // FRAMEELEMENT_H
