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



    /**
     * This creates an initial frameElement p for the
     * initial frame that will be in the "previous" or
     * leftmost position in the UI.  It assigns a name,
     * a height, a width, whether it is the currently viewed
     * frame, ties it to a specific UI frame, and sets up
     * its grid.  It then also fills that grid with all of
     * the cells required by height and width.
     */



    frameElement p;                                 // for adding the first pre-set frame to the list
    p.name = 1;                                     // first frame, so #1
    p.height = 20;                                  // heighth is 20 for now
    p.width = 8;                                    // width is 8 for now
    p.isCurrent = false;                            // does not start out as the current frame
    p.self = ui->previousFrame;                     // tying it to the UI Element
    p.grid = new QGridLayout(this);                 // set up the grid
    setup( p );                                     // set up the cells
    listFrames.push_front(p);                       // push it to the front of the list

    /**
     * This creates an initial frameElement q for the
     * initial frame that will be in the "current" or
     * center position in the UI.  It assigns a name,
     * a height, a width, whether it is the currently viewed
     * frame, ties it to a specific UI frame, and sets up
     * its grid.  It then also fills that grid with all of
     * the cells required by height and width.
     */

    frameElement q;                                 // second frame
    q.name = 2;                                     // second frame, #2
    q.height = 20;                                  // defaults
    q.width = 8;
    q.isCurrent = true;                             // starts out as the current frame
    q.self = ui->currentFrame;                      // tying to appropriate UI element
    q.grid = new QGridLayout(this);
    setup( q );
    listFrames.push_back( q );                        // put it after the first frame in the list

    /**
     * This creates an initial frameElement r for the
     * initial frame that will be in the "next" or
     * rightmost position in the UI.  It assigns a name,
     * a height, a width, whether it is the currently viewed
     * frame, ties it to a specific UI frame, and sets up
     * its grid.  It then also fills that grid with all of
     * the cells required by height and width.
     */

    frameElement r;                                 // third pre-set frame
    r.name = 3;                                     // third frame, #3
    r.height = 20;                                  // etc.
    r.width = 8;
    r.isCurrent = false;
    r.self = ui->nextFrame;
    r.grid = new QGridLayout(this);
    setup( r );
    listFrames.push_back(r);                        // last pre-set frame, so placed at the end of the list



    // BEGIN NEW STUFF

    /** These lines apply the developed grids of the frameElements
      * to the UI frames themselves.  Since the first 3 frames
      * are defaults, then this can be done statically
      */

    ui->currentFrame->setLayout( q.grid );
    ui->previousFrame->setLayout( p.grid );
    ui->nextFrame->setLayout( r.grid );

    /** These lines setup an iterator on the list of frameElements
      * The iterator, currFrame, was defined in the .h and should
      * always point the to the frame currently being viewed
      * Initially, that should be the middle frame in the list
      */


    for( currFrame = listFrames.begin(); currFrame != listFrames.end(); currFrame++ )  // Setup the iterator that points to the current frame
    {
        if( currFrame->isCurrent == true )            // Current Frame will always have isCurrent == true
        {
            break;
        }
    }

    // END NEW STUFF
}

/**
 * @brief EditorWindow::~EditorWindow
 */

EditorWindow::~EditorWindow()
{
    delete ui;
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
    frameElement p = listFrames.front();
    frameElement q = listFrames.back();
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
            next->self->move( 350, 180 );               // move the next frame left to center
            next->self->resize( 290, 350 );             // resize it accordingly
            next->self->show();                         // make sure it is visible
            next->isCurrent = true;                     // update the boolean
            currFrame->self->move( 30, 220 );           // move the current frame to left
            currFrame->self->resize( 210, 260 );        // resize accordingly
            currFrame->self->show();                    // make sure visible
            currFrame->isCurrent = false;               // update the boolean
            afterNext->self->show();                    // show the frame after next
            currFrame = next;                           // update the iterator to point to the current frame

        }
        else                                            // when the Current frame is a middle frame
        {
            ui->nextFrameTable->resize( 290, 350 );
            prev->self->hide();                         // hide the previous frame
            currFrame->self->move( 30, 220 );           // move the current frame left
            currFrame->self->resize( 210, 260 );        // resize it accordingly
            currFrame->self->show();                    // make sure it is visible
            currFrame->isCurrent = false;               // update the boolean
            next->self->move( 350, 180 );               // move the next frame left
            next->self->resize( 290, 350 );             // resize it accordingly
            next->self->show();                         // make sure it is visible
            next->isCurrent = true;                     // update the boolean
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

    frameElement p = listFrames.front();
    frameElement q = listFrames.back();


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
            prev->self->move( 350, 180 );                   // move the previous frame to the center "Go Right"
            prev->self->resize( 290, 350 );                 // change the size to accomodate its position
            prev->self->show();                             // make sure it is visible
            prev->isCurrent = true;                         // set its isCurrent to true
            currFrame->self->move( 740, 220 );              // move the current frame to the right "Go Right"
            currFrame->self->resize( 210, 260 );            // resize the frame to accomodate its position
            currFrame->self->show();                        // make sure it is visible
            currFrame->isCurrent = false;                   // set its isCurrent to false, as no longer current
            beforePrev->self->show();                       // show the frame before previous
            currFrame = prev;                               // update the iterator to point to the current frame

        }
        else                                                // When the Current Frame is in the center
        {
            ui->previousFrameTable->resize( 290, 350 );
            next->self->hide();                             // hide the next frame
            currFrame->self->move( 740, 220 );              // Moving, resizing, and showing the current frame in the "next" position
            currFrame->self->resize( 210, 260 );
            currFrame->self->show();
            currFrame->isCurrent = false;                   // Set its boolean to false
            prev->self->move( 350, 180 );                   // take the previous frame and put it in the center position
            prev->self->resize( 290, 350 );
            prev->self->show();
            prev->isCurrent = true;                         // Set its boolean to true
            currFrame = prev;                               // Update the iterator

        }
    }

}

void EditorWindow::setup( frameElement q )
{

    for( int i = 0; i < nrows; i++ )                   // defaults
    {
        for( int j = 0; j < ncolumns; j++ )
        {
            q.cellGrid[j][i].setColor( 0, 0, 0 );
            currCells = createCell();
            q.grid->addWidget( currCells, i, j, 0 );
            q.cellGrid[j][i].setCell( currCells );
        }
    }

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
    newCell->setStyleSheet( "border: 1px solid;" "background-color: blue");     // Set the style
    return newCell;                                                             // return it
}


