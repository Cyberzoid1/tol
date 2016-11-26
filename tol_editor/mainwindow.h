/**
* @author ...
* @date 11/20/2016
* @class MainWindow
* @brief This is the header file defining the MainWindow Class
* @details This header file defines the MainWindow class which is object in
* the Tower Lights Animator that contains all of the different User Interface
* functionality as well as the different objects that make up the animation itself.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "animation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui; //!< Reference to the internal UI object
    Animation *animation;
};

#endif // MAINWINDOW_H
