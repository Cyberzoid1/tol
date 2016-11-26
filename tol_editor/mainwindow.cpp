/**
* @class MainWindow
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"
#include "outputfile.h"

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
/**
 * Slot for the 'Open' action in the 'File' menu. Reads in an animation
 * from a .tan2 file.
 */
void MainWindow::on_actionOpen_triggered()
{
    //obtain the name of the file to open from the dialog
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "",
                                                    tr("TAN Files (*.tan2)"));
    //read in the animation from the file and store it in the window's
    //data object
    *animation = readInAnimation(filename.toStdString().c_str());
}
/**
 * Slot for the 'Save' action in the 'File' menu. Writes the animation out
 * to the specified .tan2 file.
 */
void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Animation"),
                                                       "",
                                                       tr("TAN Files (*.tan2)"));
    writeFile(filename.toStdString(), animation);
}
