#include "editorwindow.h"
#include "ui_editorwindow.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    EditorWindow::frameElement *p;
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

    start->next = q;

    for( frameElement *p = start; p != NULL; p = p->next )
    {

    }



}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::update()
{
    frameElement* p;
    frameElement* q;
    p = start;
    /*QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize(); */
    if( p->next->isCurrent == 1 ) //currSize != curr1Size && currSize != curr2size )
    {
        //currSize = curr1Size;
        p = p->next;
        q = p->next;
        p->isCurrent = 0;
        q->isCurrent = 1;
        p->self->resize( 210, 260 );
        p->self->move( 30, 220 );
        q->self->move( 350, 180 );
        q->self->resize( 290, 350 );
        ui->nextFrameTable->resize( 290, 350 );
        start->self->hide();
    }
    else if( p->isCurrent == 1 ) //currSize == curr2size && currSize != curr1Size )
    {
        q = p;
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
        p->next->self->show();
    }

}

void EditorWindow::lower()
{
    /*QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize();*/
    frameElement *p;
    frameElement *q;
    p = start;

    if( p->next->isCurrent == 0 && p->isCurrent == 0 ) //curr1Size == currSize && currSize != curr2size )
    {
        p = p->next;
        q = p->next;
        p->isCurrent = 1;
        q->isCurrent = 0;
        p->self->resize( 290, 350 );
        ui->currentFrameTable->resize( 290, 350 );
        p->self->move( 350, 180 );
        q->self->resize( 210, 260 );
        ui->nextFrameTable->resize( 210, 260 );
        q->self->move( 740, 220 );
        start->self->show();
    }
    else if( p->isCurrent == 0 && p->next->isCurrent == 1 ) //curr1Size == curr2size )
    {
        q = p;
        p = p->next;
        q->isCurrent = 1;
        p->isCurrent = 0;
        p->self->resize( 210, 260 );
        p->self->move( 740, 220 );
        q->self->resize( 290, 350 );
        ui->previousFrameTable->resize( 290, 350 );
        q->self->move( 350, 180 );
        p->next->self->hide();
    }
}

void EditorWindow::setup()
{

}
