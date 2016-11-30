#ifndef FRAMEELEMENT_H
#define FRAMEELEMENT_H

#include <QWidget>
#include <QFrame>

class cell
{
    int red;
    int green;
    int blue;
    QWidget* self;
public:
    void setColor( int r, int g, int b );
};


class frameElement                             // nodes for the list of ui frames
{
public:
    QFrame* self;                               // the frame belonging to the node
    QGridLayout *grid;
    bool isCurrent;                             // if the node is the current frame being viewed
    cell cellGrid[8][20];                       // array of cells for the grid
    int name;                                   // the number identifying the frame
    int width;                                  // the width of the frame
    int height;                                 // the height of the frame
};

#endif // FRAMEELEMENT_H
