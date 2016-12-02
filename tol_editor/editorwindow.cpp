#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <list>
#include <iterator>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QtAlgorithms>

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    //ui->CurrentFrameGrid = new QGridLayout;
    //ui->previousFrameGrid = new QGridLayout;
    //ui->nextFrameGrid = new QGridLayout;


    frameElement p;                   // for adding the first pre-set frame to the list
    p.name = 1;                                     // first frame, so #1
    p.height = 20;                                  // heighth is 20 for now
    p.width = 8;                                    // width is 8 for now
    p.isCurrent = false;                            // does not start out as the current frame
    p.self = ui->previousFrame;                     // tying it to the UI Element
    p.grid = new QGridLayout(this);                       // set up the grid

    //QPushButton* button1 = new QPushButton;
    //p.grid->addWidget( button1 );


    for( int i = 0; i < nrows; i++ )                   // set up the cells with black
    {
        for( int j = 0; j < ncolumns; j++ )
        {
            p.cellGrid[j][i].setColor( 0, 0, 0 );
            prevCells = createCell();
            p.grid->addWidget( prevCells, i, j, 0 );
        }
    }
    listFrames.push_front(p);                       // push it to the front of the list

    frameElement q;                   // second frame
    q.name = 2;                                     // second frame, #2
    q.height = 20;                                  // same as above
    q.width = 8;
    q.isCurrent = true;                             // starts out as the current frame
    q.self = ui->currentFrame;                      // tying to appropriate UI element
    q.grid = new QGridLayout(this);

    //QPushButton* button2 = new QPushButton;
    //QPushButton* button3 = new QPushButton;

    //q.grid->addWidget( button2 );
    //q.grid->addWidget( button3 );

    for( int i = 0; i < nrows; i++ )                   // same as above
    {
        for( int j = 0; j < ncolumns; j++ )
        {
            q.cellGrid[j][i].setColor( 0, 0, 0 );
            currCells = createCell();
            q.grid->addWidget( currCells, i, j, 0 );
        }
    }
    listFrames.push_back(q);                        // put it after the first frame in the list

    frameElement r;                   // third pre-set frame
    r.name = 3;                                     // third frame, #3
    r.height = 20;                                  // etc.
    r.width = 8;
    r.isCurrent = false;
    r.self = ui->nextFrame;
    r.grid = new QGridLayout(this);

    //QPushButton* button4 = new QPushButton;
    //r.grid->addWidget( button4 );

    for( int i = 0; i < 20; i++ )
    {
        for( int j = 0; j < 8; j++ )
        {
           r.cellGrid[j][i].setColor( 0, 0, 0 );
           nxtCells = createCell();
           r.grid->addWidget( nxtCells, i, j, 0 );
        }
    }
    listFrames.push_back(r);                        // last pre-set frame, so placed at the end of the list


    //for( frameElement *p = start; p != NULL; p = p->next )
    //{

    //}
    // BEGIN NEW STUFF

    ui->currentFrame->setLayout( q.grid );
    ui->previousFrame->setLayout( p.grid );
    ui->nextFrame->setLayout( r.grid );
    for( currFrame = listFrames.begin(); currFrame != listFrames.end(); currFrame++ )
    {
        if( currFrame->isCurrent == true )            // Current Frame will always have isCurrent == true
        {
            break;
        }
    }

    // END NEW STUFF
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::update()
{
    /* This is for when the user clicks the "Go-Left Button"
     * It should take the view left depending on the current
     * state of true and false in the isCurrent field of the
     * frameElement clas
     */
    frameElement p = listFrames.front();
    frameElement q = listFrames.back();
    std::list<frameElement>::iterator it = std::next( listFrames.begin(), 1 );
    bool prevExist, nextExist;

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

    if( prevExist ==  false )
    {


        afterNext = std::next( currFrame, 2 );
        next->self->move( 350, 180 );
        next->self->resize( 290, 350 );
        next->self->show();
        next->isCurrent = true;
        currFrame->self->move( 30, 220 );
        currFrame->self->resize( 210, 260 );
        currFrame->self->show();
        currFrame->isCurrent = false;
        afterNext->self->show();
        currFrame = next;

    }
    else
    {
        prev->self->hide();
        currFrame->self->move( 30, 220 );
        currFrame->self->resize( 210, 260 );
        currFrame->grid = ui->nextFrameGrid;
        currFrame->self->show();
        currFrame->isCurrent = false;
        next->self->move( 350, 180 );
        next->self->resize( 290, 350 );
        next->self->show();
        next->isCurrent = true;
        currFrame = next;


    }

    /*if( listFrames.size() > 3 )
    {
        std::list<frameElement>::iterator frameIt;      // Iterator for finding the current frame
        for( frameIt = listFrames.begin(); frameIt != listFrames.end(); frameIt++ )
        {
            if( frameIt->isCurrent == true )            // Current Frame will always have isCurrent == true
            {
                break;
            }
        }
        // Retrieving the relevant frameElements from the list by use of the iterator
        int size = listFrames.size();
        frameElement currFrameEl = *frameIt;
        frameElement prevFrameEl;
        if( currFrameEl.name != 1 )
        {
            prevFrameEl = *( std::next( frameIt, -1 ) );
        }
        frameElement nextFrameEl;
        if( currFrameEl.name < size )
        {
           nextFrameEl = *( std::next( frameIt, 1 ) );
        }
        frameElement nextnextFrameEl;
        if( size > 3 )
        {
            nextnextFrameEl = *( std::next( frameIt, 2 ) );
        }
        // Manipulate the above to produce the shift left
        prevFrameEl.self->hide();

        currFrameEl.self->resize( 210, 260 );
        currFrameEl.self->move( 30, 220 );

        nextFrameEl.self->resize( 290, 350 );
        nextFrameEl.self->move( 350, 180 );

        if( listFrames.size() > 3 )//&& nextFrameEl != listFrames.end()->self )
        {
            nextnextFrameEl.self->show();
        }

    }
    else
    {
        if( it->isCurrent == true )                                 // if the center frame is current, it should go left and last frame should be current
        {
            it->isCurrent = false;                                  // should no longer be current
            listFrames.back().isCurrent = true;                     // the back should now be current

            it->self->resize( 210, 260 );                           // resize the middle frame
            it->self->move( 30, 220 );                              // move it left
            it->self->show();                                       // make sure it is visible

            q.self->move( 350, 180 );                               // move the last frame to center
            q.self->resize( 290, 350 );                             // resize it
            q.self->show();                                         // make sure it is visible

            p.self->hide();                                         // hide the first frame
            ui->nextFrameTable->resize( 290, 350 );

            /*ui->CurrentFrameGrid = q.grid;
            ui->previousFrameGrid = it->grid;
            ui->nextFrameGrid = ui->NullLayout;
            */
            //ui->currentFrame->
            /*
            qDeleteAll( ui->previousFrame->children() );            // The NEW STUFF
            //qDeleteAll( ui->previousFrame->children() );
            //qDeleteAll( ui->nextFrame->children() );

            ui->previousFrame->setLayout( it->grid );

            ui->currentFrame->setLayout( q.grid );

            ui->nextFrame->setLayout( ui->NullLayout );             // END NEW STUFF

            it->isCurrent = false;
            listFrames.back().isCurrent = true;



        }
        else if( listFrames.front().isCurrent == true )             // if the first frame is in the center, it should go left and the middle frame should be in center again
        {

            listFrames.front().isCurrent = false;                   // first frame should not be current
            it->isCurrent = true;                                   // middle frame should be current

            it->self->resize( 290, 350 );                           // resize center frame
            it->self->move( 350, 180 );                             // move it into place
            it->self->show();                                       // make sure it is visible

            q.self->show();                                         // make the last frame visible again

            p.self->resize( 210, 260 );                             // resize the first frame
            p.self->move( 30, 220 );                                // move it left
            p.self->show();                                         // make sure it is visible
            /*
            ui->CurrentFrameGrid = it->grid;
            ui->previousFrameGrid = p.grid;
            ui->nextFrameGrid = q.grid;

            it->isCurrent = true;
            listFrames.front().isCurrent = false;                   // BEGIN NEW STUFF
            qDeleteAll( ui->previousFrame->children() );
            ui->previousFrame->setLayout( p.grid );
            ui->currentFrame->setLayout( it->grid );
            ui->nextFrame->setLayout( q.grid );
                                                                    // END NEW STUFF


        }
        else
        {
            //
        }
    } */


}

void EditorWindow::lower()
{

    /* When the user clicks the "go-right" button
     * It should take the user right depending on the current
     * state of true and false in the isCurrent field of the
     * frameElement class
     */

    frameElement p = listFrames.front();
    frameElement q = listFrames.back();


    std::list<frameElement>::iterator it = std::next( listFrames.begin(), 1 );
    bool prevExist, nextExist;

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

    if( nextExist ==  false )
    {
        beforePrev = std::next( currFrame, -2 );
        prev->self->move( 350, 180 );
        prev->self->resize( 290, 350 );
        prev->self->show();
        prev->isCurrent = true;
        currFrame->self->move( 740, 220 );
        currFrame->self->resize( 210, 260 );
        currFrame->self->show();
        currFrame->isCurrent = false;
        beforePrev->self->show();
        currFrame = prev;

    }
    else                                            // When the Current Frame is in the center
    {

        next->self->hide();                         // hide the next frame
        currFrame->self->move( 740, 220 );          // Moving, resizing, and showing the current frame in the "next" position
        currFrame->self->resize( 210, 260 );
        currFrame->self->show();
        currFrame->isCurrent = false;               // Set its boolean to false
        prev->self->move( 350, 180 );               // take the previous frame and put it in the center position
        prev->self->resize( 290, 350 );
        prev->self->show();
        prev->isCurrent = true;                     // Set its boolean to true
        currFrame = prev;                           // Update the iterator

    }

    /*

    if( listFrames.size() > 3 )
    {
        int size = listFrames.size();
        std::list<frameElement>::iterator frameIt;
        for( frameIt = listFrames.begin(); frameIt != listFrames.end(); frameIt++ )
        {
            if( frameIt->isCurrent == true )
            {
                break;
            }
        }

        frameElement currFrameEl = *frameIt;
        frameElement prevFrameEl;
        frameElement nextFrameEl;
        frameElement prevPrevFrameEl;

        if( currFrameEl.name != 1 )
        {
            prevFrameEl = *( std::next( frameIt, -1 ) );
            if( size > 3 )
            {
                prevPrevFrameEl = *( std::next( frameIt, -2 ) );
            }
        }
        if( currFrameEl.name < size )
        {
            nextFrameEl = *( std::next( frameIt, 1 ) );
        }



    }
    else
    {
        if( q.isCurrent == true )                   // if the last frame is the current one
        {
                                                    // if the last frame is current, and user clicks to move things right, then all 3
                                                   // should be visible
            listFrames.back().isCurrent = false;    // set the last frame to false
            it->isCurrent = true;                   // set the previous one to true

            q.self->move( 740, 220 );               // move the last frame right
            q.self->resize( 210, 260 );             // resize it
            q.self->show();                         // make sure it is visible

            it->self->move( 350, 180 );             // move the previous frame to middle
            it->self->resize( 290, 350 );           // resize it
            it->self->show();                       // show it

            p.self->show();                         // show the first frame


            /*
            ui->CurrentFrameGrid = it->grid;
            ui->previousFrameGrid = p.grid;
            ui->nextFrameGrid = q.grid;


            //qDeleteAll( ui->nextFrame->children() );
            ui->nextFrame->setLayout( q.grid );     // BEGIN NEW STUFF
            ui->currentFrame->setLayout( it->grid );
            ui->previousFrame->setLayout( p.grid );
                                                    // END NEW STUFF
            listFrames.back().isCurrent = false;
            it->isCurrent = true;

        }
        else if( p.isCurrent == false && q.isCurrent == false ) // if both the front and back are false, then the middle should be current
        {

            it->isCurrent = false;                              // middle should no longer be current
            listFrames.front().isCurrent = true;                // the first frame should now be visible

            it->self->resize( 210, 260 );                       // resize the middle
            it->self->move( 740, 220 );                         // move the middle one to the right
            it->self->show();                                   // make sure the middle is still visible

            p.self->resize( 290, 350 );                         // resize the first frame
            ui->previousFrameTable->resize( 290, 350 );         // frameTable--unimportant right now
            p.self->move( 350, 180 );                           // move the first frame to the center spot
            p.self->show();                                     // make sure it is visible

            q.self->hide();                                     // hide the rightmost frame
            /*
            ui->CurrentFrameGrid = p.grid;
            ui->previousFrameGrid = ui->NullLayout;
            ui->nextFrameGrid = it->grid;

            qDeleteAll( ui->nextFrame->children() );            // BEGIN NEW STUFF
            ui->nextFrame->setLayout( it->grid );
            ui->currentFrame->setLayout( p.grid );
            //ui->previousFrame->setLayout( ui->NullLayout );     // END NEW STUFF
            it->isCurrent = false;
            listFrames.front().isCurrent = true;

        }
    }
    */
}
void EditorWindow::setup()
{


}


QPushButton* EditorWindow::createCell()     // Definition of the createCell function
{
    QPushButton* newCell;                   // create the new cell
    newCell = new QPushButton;              // assign it some memory
    return newCell;                         // return it
}


