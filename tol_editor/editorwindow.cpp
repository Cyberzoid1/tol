#include "editorwindow.h"
#include "ui_editorwindow.h"



EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncolumns; j++)
        {


           currCells = new QPushButton();
           prevCells = new QPushButton();
           nxtCells = new QPushButton();

           currCells -> setStyleSheet("background-color: gray;" "border: solid");
           prevCells -> setStyleSheet("background-color: gray");
           nxtCells -> setStyleSheet("background-color: gray");
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





