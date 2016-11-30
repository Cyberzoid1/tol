#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <list>
#include <iterator>

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);


    EditorWindow::frameElement p;                   // for adding the first pre-set frame to the list
    p.name = 1;                                     // first frame, so #1
    p.height = 20;                                  // heighth is 20 for now
    p.width = 8;                                    // width is 8 for now
    p.isCurrent = false;                            // does not start out as the current frame
    p.self = ui->previousFrame;                     // tying it to the UI Element
    for( int i = 0; i < 20; i++ )                   // set up the cells with black
    {
        for( int j = 0; j < 8; j++ )
        {
            p.cellGrid[j][i].setColor( 0, 0, 0 );
        }
    }
    listFrames.push_front(p);                       // push it to the front of the list

    EditorWindow::frameElement q;                   // second frame
    q.name = 2;                                     // second frame, #2
    q.height = 20;                                  // same as above
    q.width = 8;
    q.isCurrent = true;                             // starts out as the current frame
    q.self = ui->currentFrame;                      // tying to appropriate UI element
    for( int i = 0; i < 20; i++ )                   // same as above
    {
        for( int j = 0; j < 8; j++ )
        {
            q.cellGrid[j][i].setColor( 0, 0, 0 );
        }
    }
    listFrames.push_back(q);                        // put it after the first frame in the list

    EditorWindow::frameElement r;                   // third pre-set frame
    r.name = 3;                                     // third frame, #3
    r.height = 20;                                  // etc.
    r.width = 8;
    r.isCurrent = false;
    r.self = ui->nextFrame;
    for( int i = 0; i < 20; i++ )
    {
        for( int j = 0; j < 8; j++ )
        {
           r.cellGrid[j][i].setColor( 0, 0, 0 );
        }
    }
    listFrames.push_back(r);                        // last pre-set frame, so placed at the end of the list


    //for( frameElement *p = start; p != NULL; p = p->next )
    //{

    //}



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
    auto it = std::next( listFrames.begin(), 1 );
    std::list<frameElement>::iterator frameIt;
    for( frameIt = listFrames.begin(); frameIt != listFrames.end(); frameIt++ )
    {
        if( frameIt->isCurrent == true )
        {
            break;
        }
    }
    // Retrieving the relevant frameElements from the list by use of the iterator
    frameElement currFrameEl = *frameIt;
    frameElement prevFrameEl = *( std::next( frameIt, -1 ) );
    frameElement nextFrameEl = *( std::next( frameIt, 1 ) );


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



    }
    else
    {
        //
    }


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
    auto it = std::next( listFrames.begin(), 1 );

    std::list<frameElement>::iterator frameIt;
    for( frameIt = listFrames.begin(); frameIt != listFrames.end(); frameIt++ )
    {
        if( frameIt->isCurrent == true )
        {
            break;
        }
    }

    frameElement currFrameEl = *frameIt;
    frameElement prevFrameEl = *( std::next( frameIt, -1 ) );
    frameElement nextFrameEl = *( std::next( frameIt, 1 ) );



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
    }
}

void EditorWindow::setup()
{


}

void EditorWindow::cell::setColor(int r, int g, int b)
{
    cell::red = r;
    cell::green = g;
    cell::blue = b;
}
