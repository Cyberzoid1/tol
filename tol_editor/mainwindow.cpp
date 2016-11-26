/**
* @class MainWindow
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    animation = new Animation();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    *animation = readInAnimation("../../tan_files/Sample3.tan2");
}
