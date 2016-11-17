#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_redBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void MainWindow::on_greenBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void MainWindow::on_blueBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void MainWindow::on_redSlider_valueChanged(int value)
{

}

void MainWindow::on_greenSlider_valueChanged(int value)
{

}

void MainWindow::on_blueSlider_valueChanged(int value)
{

}

void MainWindow::on_colorHex_returnPressed()
{

}

void MainWindow::on_addFrameStart_valueChanged(int arg1)
{

}

void MainWindow::on_addFrameAmount_valueChanged(int arg1)
{

}

void MainWindow::on_addFrameConfirm_clicked()
{

}

void MainWindow::on_removeFrameFirst_valueChanged(int arg1)
{

}

void MainWindow::on_removeFrameLast_valueChanged(int arg1)
{

}

void MainWindow::on_removeFrameConfirm_clicked()
{

}

void MainWindow::on_copyFrameSourceIndex_valueChanged(int arg1)
{

}

void MainWindow::on_copyFrameDestinationIndex_valueChanged(int arg1)
{

}

void MainWindow::on_copyFrameConfirmation_clicked()
{

}
