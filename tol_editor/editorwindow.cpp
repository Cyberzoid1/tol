#ifndef EditorWindow_CPP
#define EditorWindow_CPP

#include "editorwindow.h"
#include "ui_editorwindow.h"
#include "editorframe.h"


#endif

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    isCurr = false;
    EditorFrame n1, n2;
    frameList.push_back(n1);
    frameList.push_back(n2);

    ui->CurrentFrameGrid->addLayout((*frameList.begin()).getGrid(),0,0,Qt::Alignment());


//    eFrame = new EditorFrame();
//    ui->previousFrame->addLayout(eFrame->getGrid(),0,0,Qt::Alignment());
//    ui->CurrentFrameGrid->addLayout(n1.getGrid(),0,0,Qt::Alignment());
//    ui->nextFrame->addLayout(n2.getGrid(),0,0,Qt::Alignment());
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

//bool EditorWindow::isCurrent();
//{
//    return isCurr;
//}

//std::list<EditorFrame>::iterator EditorWindow::get_curr()
//{

//}

//QPushButton * EditorWindow::createCell()
//{
//    QPushButton * n = new QPushButton();
//    n->setStyleSheet("border: 1px solid;" "background-color: gray");
//    return n;
//}


