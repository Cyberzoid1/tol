#include "editorwindow.h"
#include "ui_editorwindow.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::SetTableFrames()
{
    ui->currentFrame->setShowGrid(true);
    ui->previousFrame->setShowGrid(true);
    ui->nextFrame->setShowGrid(true);
    return;
}
