#include "editorwindow.h"
#include "ui_editorwindow.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    EditorWindow::frameElement *p;
    EditorWindow::frameElement *start;
    EditorWindow::frameElement *q;
    start = new frameElement;
    start->self = ui->previousFrame;
    start->next = NULL;
    start->prev = NULL;

    q = new frameElement;
    q->self = ui->currentFrame;
    q->next = NULL;
    q->prev = start;
    p = new frameElement;
    p->self = ui->nextFrame;
    p->next = NULL;
    p->prev = q;
    q->next = p;

    start->next = q;



}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::update()
{
    QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize();
    if( currSize != curr1Size && currSize != curr2size )
    {
        currSize = curr1Size;
        ui->currentFrame->resize( 210, 260 );
        ui->currentFrame->move( 30, 220 );
        ui->nextFrame->move( 350, 180 );
        ui->nextFrame->resize( 290, 350 );
        ui->nextFrameTable->resize( 290, 350 );
        ui->previousFrame->hide();
    }
    else if( currSize == curr2size && currSize != curr1Size )
    {
        ui->previousFrame->resize( 210, 260 );
        ui->previousFrame->move( 30, 220 );
        ui->previousFrame->show();
        ui->previousFrameTable->resize( 210, 260 );
        ui->currentFrame->move( 350, 180 );
        ui->currentFrame->resize( 290, 350 );
        ui->currentFrameTable->resize( 290, 350 );
        ui->nextFrame->show();
    }

}

void EditorWindow::lower()
{
    QSize currSize = ui->currentFrame->frameSize();
    QSize curr1Size = ui->previousFrame->frameSize();
    QSize curr2size = ui->nextFrame->frameSize();

    if( curr1Size == currSize && currSize != curr2size )
    {
        ui->currentFrame->resize( 290, 350 );
        ui->currentFrameTable->resize( 290, 350 );
        ui->currentFrame->move( 350, 180 );
        ui->nextFrame->resize( 210, 260 );
        ui->nextFrameTable->resize( 210, 260 );
        ui->nextFrame->move( 740, 220 );
        ui->previousFrame->show();
    }
    else if( curr1Size == curr2size )
    {
        ui->currentFrame->resize( 210, 260 );
        ui->currentFrame->move( 740, 220 );
        ui->previousFrame->resize( 290, 350 );
        ui->previousFrameTable->resize( 290, 350 );
        ui->previousFrame->move( 350, 180 );
        ui->nextFrame->hide();
    }
}

void EditorWindow::setup()
{

}
