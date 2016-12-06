/**
* @class EditorWindow
*/


#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <list>
#include <iterator>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QtAlgorithms>

/**
 * @brief EditorWindow::EditorWindow
 * @param parent
 * The constructor sets the UI,
 * fills the list of frameElements,
 * and creates all the initial values
 */


EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    QPushButton * tempCell;

    frameElement *p = new frameElement(1, 20, 8, false, ui->previousFrame); // for adding the first pre-set frame to the list


    for( int i = 0; i < nrows; i++ )                   // set up the cells with black
    {
        for( int j = 0; j < ncolumns; j++ )
        {
            p->cellGrid[j][i].setColor( 0, 0, 0 );
            tempCell = createCell();
            p->grid->addWidget( tempCell, i, j, 0 );
        }
    }
    listFrames.push_front(*p);                       // push it to the front of the list


    frameElement *q = new frameElement(2, 20, 8, true, ui->currentFrame);                                 // second frame

    for( int i = 0; i < nrows; i++ )                   // defaults
    {
        for( int j = 0; j < ncolumns; j++ )
        {
            q->cellGrid[j][i].setColor( 0, 0, 0 );
            tempCell = createCell();
            q->grid->addWidget( tempCell, i, j, 0 );
        }
    }
    listFrames.push_back(*q);                        // put it after the first frame in the list


    frameElement *r = new frameElement(3, 20, 8, false, ui->nextFrame); // third pre-set frame

    for( int i = 0; i < 20; i++ )
    {
        for( int j = 0; j < 8; j++ )
        {
           r->cellGrid[j][i].setColor( 0, 0, 0 );
           tempCell = createCell();
           r->grid->addWidget( tempCell, i, j, 0 );
        }
    }
    listFrames.push_back(*r);                        // last pre-set frame, so placed at the end of the list


    /** These lines apply the developed grids of the frameElements
      * to the UI frames themselves.  Since the first 3 frames
      * are defaults, then this can be done statically
      */

    std::list<frameElement>::iterator temp = listFrames.begin();

    ui->currentFrame->setLayout((*temp).grid);
    ui->previousFrame->setLayout((*++temp).grid);
    ui->nextFrame->setLayout((*++temp).grid);


    /** These lines setup an iterator on the list of frameElements
      * The iterator, currFrame, was defined in the .h and should
      * always point the to the frame currently being viewed
      * Initially, that should be the middle frame in the list
      */

    setCurrentFrame();

}

/**
 * @brief EditorWindow::~EditorWindow
 */

EditorWindow::~EditorWindow()
{
    delete ui;
}


void EditorWindow::setCurrentFrame()
{
    for( currFrame = listFrames.begin(); currFrame != listFrames.end(); currFrame++ )  // Setup the iterator that points to the current frame
    {
        if( currFrame->isCurrent == true )            // Current Frame will always have isCurrent == true
        {
            break;
        }
    }
    return;
}



/**
 * @brief EditorWindow::update
 * This is the slot for when the
 * "Go-Right" Button is clicked
 * by the user
 */

void EditorWindow::update()
{
    /** This is for when the user clicks the "Go-Left Button"
     * It should take the UI view left depending on the current
     * state of true and false in the isCurrent field of the
     * frameElement nodes in the std::list listFrames
     */

    std::list<frameElement>::iterator it = std::next( listFrames.begin(), 1 );
    bool prevExist, nextExist;

    /**
     * @brief This section creates iterators previous to and after
     * the iterator that always points to the current-viewed frame.
     * These iterators will allow the program to manipulate the frames
     * around the current frame as well as the current frame itself.
     * The iterators must be dynamic to accomodate arbitrarily large
     * lists of frames.  This section also assigns values to the booleans
     * prevExist and nextExist, which values indicate whether the view is
     * at the head or the back of the list.  If one of those is the case,
     * then the booleans prevent stepping off the list.
     */

    std::list<frameElement>::iterator prev, next, beforePrev, afterNext;        // Defines a previous, a next, and for larger lists
    if( currFrame == listFrames.begin() )                                       // it also defines iterators for after the next and
    {                                                                           // before the previous
        prevExist = false;
        next = std::next( currFrame, 1 );
        if( listFrames.size() > 3 )
        {
            afterNext = std::next( currFrame, 2);
        }
    }
    else if( currFrame == listFrames.end() )
    {
        nextExist = false;
        prev = std::next( currFrame, -1 );
        if( listFrames.size() > 3 )
        {
            beforePrev = std::next( currFrame, -2 );
        }
    }
    else
    {
        nextExist = true;
        prevExist = true;
        next = std::next( currFrame, 1 );
        prev = std::next( currFrame, -1 );
    }

    /** This section actually performs the manipulation.
      * First, it checks if the user is as far left as
      * possible; if so, then the user cannot proceed farther left.
      * Otherwise, the program evaluates the values of prevExist and
      * isCurrent and performs the required motion.
      */


    if( currFrame->name == listFrames.size() )
    {
        //
    }
    else
    {

        if( prevExist ==  false )                       // if the user is at the farthest right
        {

            ui->nextFrameTable->resize( 290, 350 );
            afterNext = std::next( currFrame, 2 );      // assign the frame after next to the afterNext iterator
            moveCent( next );
            moveLeft( currFrame );
            afterNext->self->show();                    // show the frame after next
            currFrame = next;                           // update the iterator to point to the current frame

        }
        else                                            // when the Current frame is a middle frame
        {
            ui->nextFrameTable->resize( 290, 350 );
            prev->self->hide();                         // hide the previous frame
            moveLeft( currFrame );
            moveCent( next );
            currFrame = next;                           // update the iterator to point to the current frame

        }
    }
}


/**
 * @brief EditorWindow::lower
 * This is the slot used when the user
 * clicks the "Go-Right" button.
 */

void EditorWindow::lower()
{

    /** When the user clicks the "go-right" button
     * It should take the user right depending on the current
     * state of true and false in the isCurrent field of the
     * frameElement class nodes of the std::list listFrames
     */


    std::list<frameElement>::iterator it = std::next( listFrames.begin(), 1 );
    bool prevExist, nextExist;

    /**
     * @brief This section creates iterators previous to and after
     * the iterator that always points to the current-viewed frame.
     * These iterators will allow the program to manipulate the frames
     * around the current frame as well as the current frame itself.
     * The iterators must be dynamic to accomodate arbitrarily large
     * lists of frames.  This section also assigns values to the booleans
     * prevExist and nextExist, which values indicate whether the view is
     * at the head or the back of the list.  If one of those is the case,
     * then the booleans prevent stepping off the list.
     */

    std::list<frameElement>::iterator prev, next, beforePrev, afterNext;
    if( currFrame == listFrames.begin() )
    {
        prevExist = false;
        next = std::next( currFrame, 1 );
        if( listFrames.size() > 3 )
        {
            afterNext = std::next( currFrame, 2);
        }
    }
    else if( currFrame == std::next( listFrames.end(), -1 ) )
    {
        nextExist = false;
        prev = std::next( currFrame, -1 );
        if( listFrames.size() > 3 )
        {
            beforePrev = std::next( currFrame, -2 );
        }
    }
    else
    {
        nextExist = true;
        prevExist = true;
        next = std::next( currFrame, 1 );
        prev = std::next( currFrame, -1 );
    }

    /** This section actually performs the manipulation.
      * First, it checks if the user is as far right as
      * possible; if so, then the user cannot proceed farther right.
      * Otherwise, the program evaluates the values of nextExist and
      * isCurrent and performs the required motion.
      */
    if( listFrames.begin()->isCurrent == true )
    {
        //
    }
    else
    {
        if( nextExist ==  false )                           // when the user is at the farthest left
        {
            ui->previousFrameTable->resize( 290, 350 );
            beforePrev = std::next( currFrame, -2 );        // Assign beforePrev to the frame before prev
            moveCent( prev );
            moveRght( currFrame );
            beforePrev->self->show();                       // show the frame before previous
            currFrame = prev;                               // update the iterator to point to the current frame

        }
        else                                                // When the Current Frame is in the center
        {
            ui->previousFrameTable->resize( 290, 350 );
            next->self->hide();                             // hide the next frame
            moveRght( currFrame );
            moveCent( prev );
            currFrame = prev;                               // Update the iterator

        }
    }

}

void EditorWindow::moveLeft( std::list<frameElement>::iterator q )
{
    q->self->move( 30, 220 );
    q->self->resize( 210, 260 );
    q->self->show();
    q->isCurrent = false;
}

void EditorWindow::moveCent( std::list<frameElement>::iterator q )
{
    q->self->move( 350, 180 );
    q->self->resize( 290, 350 );
    q->self->show();
    q->isCurrent= true;
    //q->setCurrClickable();
}

void EditorWindow::moveRght( std::list<frameElement>::iterator q )
{
    q->self->move( 740, 220 );
    q->self->resize( 210, 260 );
    q->self->show();
    q->isCurrent = false;
}

void EditorWindow::setup()
{


}

/**
 * @brief EditorWindow::createCell
 * this creates a new QPushbutton with
 * our own style.
 * @return a pointer to a QPushButton, as
 * that is the implementation of our cells
 * in the UI
 */


QPushButton* EditorWindow::createCell()                                         // Definition of the createCell function
{
    QPushButton* newCell;                                                       // create the new cell
    newCell = new QPushButton;                                                  // assign it some memory
    newCell->setStyleSheet("border: 1px solid; background-color: gray");     // Set the style
    connect(newCell, SIGNAL(clicked()), newCell, SLOT(EditorWindow::handleCellColor(newCell)));
    return newCell;                                                             // return it
}

void EditorWindow::handleCellColor(QPushButton *temp)
{
    temp->setStyleSheet("background-color: blue");
    return;
}

