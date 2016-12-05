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
//#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QAbstractButton>

#define nrows 20
#define ncolumns 8

class cell
{
    int red;                                    //!< A number to hold red values
    int green;                                  //!< A number to hold green values
    int blue;                                   //!< A number to hold blue values
    QPushButton* self;                          //!< A pointer to the QPushButton the cell refers to
public:
    void setColor( int r, int g, int b );
};


class frameElement: public QObject                             // nodes for the list of ui frames
{
    Q_OBJECT
public:
    frameElement();
    frameElement(const frameElement &obj);      //!< Explicit copy constructor
    frameElement(int Name, int Height, int Width, bool Curr, QFrame * Self);
    QFrame* self;                               //!< A pointer to the UI frame belonging to the node
    QGridLayout *grid;                          //!< A pointer to the grid layout of the node
    bool isCurrent;                             //!< A boolean to hold whether the node is the current frame being viewed
    cell cellGrid[8][20];                       //!< An array of cells for the grid
    int name;                                   //!< A name, which is the number identifying the frame
    int width;                                  //!< A number holding the width of the frame
    int height;                                 //!< A number holding the height of the frame
    void setCurrClickable();
public slots:
    void handleCellColor(QPushButton * temp);
};

#endif // FRAMEELEMENT_H
