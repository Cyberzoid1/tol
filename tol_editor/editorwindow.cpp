#ifndef EditorWindow_CPP
#define EditorWindow_CPP

#include "editorwindow.h"
#include "ui_editorwindow.h"

#endif

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncolumns; j++)
        {

           currCells = createCell();
           prevCells = createCell();
           nxtCells = createCell();

           ui->currentFrame->addWidget(currCells,i,j,0);
           ui->previousFrame->addWidget(prevCells,i,j,0);
           ui->nextFrame->addWidget(nxtCells,i,j,0);
        }
    }

}

EditorWindow::~EditorWindow()
{
    delete ui;
}



QPushButton * EditorWindow::createCell()
{
    QPushButton * n = new QPushButton();
    n->setStyleSheet("border: 1px solid;" "background-color: gray");
    return n;
}


