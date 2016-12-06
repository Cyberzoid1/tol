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

    currIndex = 0;
    ui->GoLeftIcon->setEnabled(false);
    ui->GoRightIcon->setEnabled(false);
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
//    /** This is for when the user clicks the "Go-Left Button"
//     * It should take the UI view left depending on the current
//     * state of true and false in the isCurrent field of the
//     * frameElement nodes in the std::list listFrames
//     */
//    frameElement p = listFrames.front();
//    frameElement q = listFrames.back();
//    std::list<frameElement>::iterator it = std::next( listFrames.begin(), 1 );
//    bool prevExist, nextExist;

//    /**
//     * @brief This section creates iterators previous to and after
//     * the iterator that always points to the current-viewed frame.
//     * These iterators will allow the program to manipulate the frames
//     * around the current frame as well as the current frame itself.
//     * The iterators must be dynamic to accomodate arbitrarily large
//     * lists of frames.  This section also assigns values to the booleans
//     * prevExist and nextExist, which values indicate whether the view is
//     * at the head or the back of the list.  If one of those is the case,
//     * then the booleans prevent stepping off the list.
//     */

//    std::list<frameElement>::iterator prev, next, beforePrev, afterNext;        // Defines a previous, a next, and for larger lists
//    if( currFrame == listFrames.begin() )                                       // it also defines iterators for after the next and
//    {                                                                           // before the previous
//        prevExist = false;
//        next = std::next( currFrame, 1 );
//        if( listFrames.size() > 3 )
//        {
//            afterNext = std::next( currFrame, 2);
//        }
//    }
//    else if( currFrame == listFrames.end() )
//    {
//        nextExist = false;
//        prev = std::next( currFrame, -1 );
//        if( listFrames.size() > 3 )
//        {
//            beforePrev = std::next( currFrame, -2 );
//        }
//    }
//    else
//    {
//        nextExist = true;
//        prevExist = true;
//        next = std::next( currFrame, 1 );
//        prev = std::next( currFrame, -1 );
//    }

//    /** This section actually performs the manipulation.
//      * First, it checks if the user is as far left as
//      * possible; if so, then the user cannot proceed farther left.
//      * Otherwise, the program evaluates the values of prevExist and
//      * isCurrent and performs the required motion.
//      */


//    if( currFrame->name == listFrames.size() )
//    {
//        //
//    }
//    else
//    {

//        if( prevExist ==  false )                       // if the user is at the farthest right
//        {

//            ui->nextFrameTable->resize( 290, 350 );
//            afterNext = std::next( currFrame, 2 );      // assign the frame after next to the afterNext iterator
//            moveCent( next );
//            moveLeft( currFrame );
//            afterNext->self->show();                    // show the frame after next
//            currFrame = next;                           // update the iterator to point to the current frame

//        }
//        else                                            // when the Current frame is a middle frame
//        {
//            ui->nextFrameTable->resize( 290, 350 );
//            prev->self->hide();                         // hide the previous frame
//            moveLeft( currFrame );
//            moveCent( next );
//            currFrame = next;                           // update the iterator to point to the current frame


//        }
//    }
    //TODO: refactor slot names so they correlate to the buttons
    //      test on a screen that I can verify if the move is working
    //      if working, implement in other slot too
    //                  and add more error handling/checking
    frameElement newCurr, newNext;
    if (currIndex+1 < listFrames.size() - 1)
        newCurr = *std::next(currFrame, 1);
    if (currIndex+2 < listFrames.size() - 1)
        newNext = *std::next(currFrame, 2);
    std::vector<frameElement> frames = {
        newCurr,
        *currFrame,
        newNext
    };
    showFrames(frames, currIndex+1);
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

void EditorWindow::setup( frameElement q, Frame data)
{

    for( int i = 0; i < q.width; i++ )
    {
        for( int j = 0; j < q.height; j++ )
        {
            currCells = createCell(data.getCellColor(i, j));
            q.grid->addWidget( currCells, i, j, 0 );
        }
    }

}

/**
 * @brief EditorWindow::createCell
 * this creates a new QPushbutton with
 * our own style.
 * @param color RGB object containing the color value
 * @return a pointer to a QPushButton, as
 * that is the implementation of our cells
 * in the UI
 */


QPushButton* EditorWindow::createCell(RGB color)                                         // Definition of the createCell function
{
    QPushButton* newCell;                                                       // create the new cell
    newCell = new QPushButton;                                                  // assign it some memory
    QString colorStr = "background-color: rgb(" +
            QString::number(color.getRed()) +
            "," +
            QString::number(color.getGreen()) +
            "," +
            QString::number(color.getBlue()) +
            ");";
    newCell->setStyleSheet( "border: 1px solid;" + colorStr);     // Set the style
    return newCell;                                                             // return it
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
}

void EditorWindow::moveRght( std::list<frameElement>::iterator q )
{
    q->self->move( 740, 220 );
    q->self->resize( 210, 260 );
    q->self->show();
    q->isCurrent = false;
}
/**
 * Called after reading in an animation from a .tan2 file.
 * Forms a list of frameElements corresponding to the data frames.
 * Sets up the first three frames in the editor section.
 * @param animation
 */
void EditorWindow::generateUiFrames(Animation *animation)
{
    std::list<Frame> frames = animation->getFrames();
    for (auto it = frames.begin(); it != frames.end(); it++){
        frameElement newFrameEl(0,
                                animation->getHeight(),
                                animation->getWidth(),
                                false);
        setup(newFrameEl, *it);
        listFrames.push_back(newFrameEl);
    }

    //TODO: modify transition code to navigate through the whole list
    std::vector<frameElement> firstFrames = {
        *listFrames.begin(),
        placeHolder
    };
    if (listFrames.size() > 1)
        firstFrames.push_back(*std::next(listFrames.begin(), 1));
    else
        firstFrames.push_back(placeHolder);

    showFrames(firstFrames, 0);
}
/**
 * Setup the UI to contain the specified frameElements in the previousFrame,
 * currentFrame, and nextFrame positions in the EditorWindow.
 * @param frames vector of three frameElements {currFrame, prevFrame, nextFrame}
 * @param currIndex index of the current frame in the listFrames list
 * @return void
 */
void EditorWindow::showFrames(std::vector<frameElement> frames, int currIndex)
{
    std::vector<QFrame *> uiSlots = {
        ui->currentFrame,
        ui->previousFrame,
        ui->nextFrame
    };
    if (frames.size() != uiSlots.size())
        return;
    QLayout* tmp;
    for (int i = 0; i < uiSlots.size(); i++){
        frames[i].self = uiSlots[i];
        tmp = uiSlots[i]->layout();
        delete tmp;
        frames[i].self->setLayout(frames[i].grid);
    }
    this->currFrame = std::next(listFrames.begin(), currIndex);
    this->currIndex = currIndex;

    if (this->currIndex > 0)
        ui->GoLeftIcon->setEnabled(true);
    //subtract 1 from size to account for zero-based indexing
    if (this->currIndex != (listFrames.size() - 1))
        ui->GoRightIcon->setEnabled(true);
}
