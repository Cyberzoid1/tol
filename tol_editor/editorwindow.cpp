#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <list>
#include <iterator>

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    /*EditorWindow::frameElement *p;
    EditorWindow::frameElement *q;
    start = new frameElement;
    start->self = ui->previousFrame;
    start->next = NULL;
    start->prev = NULL;
    start->isCurrent = 0;
    start->name = 1;

    q = new frameElement;
    q->self = ui->currentFrame;
    q->next = NULL;
    q->prev = start;
    q->isCurrent = 1;
    q->name = 2;


    p = new frameElement;
    p->self = ui->nextFrame;
    p->next = NULL;
    p->prev = q;
    p->isCurrent = 0;
    p->name = 3;


    q->next = p;

    start->next = q; */

    //std::list<frameElement> listFrames;
    EditorWindow::frameElement p;
    p.name = 1;
    p.height = 20;
    p.width = 8;
    p.isCurrent = false;
    p.self = ui->previousFrame;
    listFrames.push_front(p);

    EditorWindow::frameElement q;
    q.name = 2;
    q.height = 20;
    q.width = 8;
    q.isCurrent = true;
    q.self = ui->currentFrame;
    listFrames.push_back(q);

    EditorWindow::frameElement r;
    r.name = 3;
    r.height = 20;
    r.width = 8;
    r.isCurrent = false;
    r.self = ui->nextFrame;
    listFrames.push_back(r);


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
    frameElement p = listFrames.front();
    //auto q = std::find( listFrames.begin(), listFrames.end(), p.name+1 );
    auto it = std::next( listFrames.begin(), 1 );
    /*frameElement* q;
    p = start;
    QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize(); */
    if( it->isCurrent == true ) //currSize != curr1Size && currSize != curr2size )
    {
        //currSize = curr1Size;
        /*p = p->next;
        q = p->next;
        p->isCurrent = 0;
        q->isCurrent = 1;
        p->self->resize( 210, 260 );
        p->self->move( 30, 220 );
        q->self->move( 350, 180 );
        q->self->resize( 290, 350 );
        ui->nextFrameTable->resize( 290, 350 );
        start->self->hide(); */
        frameElement r = listFrames.back();

        //frameElement q;
        it->isCurrent = false;
        r.isCurrent = true;
        it->self->resize( 210, 260 );
        it->self->move( 30, 220 );
        p.self->hide();
        r.self->move( 350, 180 );
        r.self->resize( 290, 350 );
        r.self->show();
        it->self->show();

    }
    else if( p.isCurrent == true ) //currSize == curr2size && currSize != curr1Size )
    {
        p.isCurrent = false;
        frameElement q = listFrames.back();
        //frameElement r = listFrames[1];
        
        /*auto it = std::find( listFrames.begin(), listFrames.end(), p.name+1);
        if( it != listFrames.end() )
        {
                it->isCurrent = true;
                it->self->resize( 290, 350 );
                it->self->move( 350, 180 );
                it->self->show();
                it++;
                it->self->show();
        }*/
        it->isCurrent = true;
        it->self->resize( 290, 350 );
        it->self->move( 350, 180 );
        it->self->show();
        q.self->show();
        p.self->resize( 210, 260 );
        p.self->move( 30, 220 );
        p.self->hide();

        /*q = p;
        p = p->next;
        q->isCurrent = 0;
        p->isCurrent = 1;
        q->self->resize( 210, 260 );
        q->self->move( 30, 220 );
        q->self->show();
        ui->previousFrameTable->resize( 210, 260 );
        p->self->move( 350, 180 );
        p->self->resize( 290, 350 );
        ui->currentFrameTable->resize( 290, 350 );
        p->next->self->show(); */
    }

}

void EditorWindow::lower()
{
    /*QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize();*/
    frameElement p = listFrames.front();
    frameElement q = listFrames.back();
    auto it = std::next( listFrames.begin(), 1 );

    //p = start;

    if( q.isCurrent == true ) //curr1Size == currSize && currSize != curr2size )
    {
        //frameElement r = listFrames[1];
        it->isCurrent = true;
        q.isCurrent = false;
        it->self->resize( 290, 350 );
        ui->currentFrameTable->resize( 290, 350 );
        it->self->move( 350, 180 );
        q.self->resize( 210, 260 );
        ui->nextFrameTable->resize( 210, 260 );
        q.self->move( 740, 220 );
        p.self->show();
        it->self->show();
    }
    else if( p.isCurrent == false && q.isCurrent == false ) //curr1Size == curr2size )
    {
        //frameElement r = listFrames[1];

        it->isCurrent = false;
        p.isCurrent = true;
        it->self->resize( 210, 260 );
        it->self->move( 740, 220 );
        p.self->resize( 290, 350 );
        ui->previousFrameTable->resize( 290, 350 );
        p.self->move( 350, 180 );
        q.self->hide();
    }
}

void EditorWindow::setup()
{

}
