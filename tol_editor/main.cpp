#include "mainwindow.h"
#include "animation.h"
#include "input.h"
#include "outputfile.h"
#include "toolbox.h"
#include <QApplication>
#include <QWidget>

/**
 * Initial point of execution for the program. Yhis function
 * will initialyze the Qt window for the Tower Lights Animator and
 * also Initialize any data structures necessary for it's function.
 * @param argc An Integer representing the number of arguments
 * passed into the application.
 * @param argv A Pointer to a character array that contains the
 * arguments passed into the application.
 * @return An Integer representing the exit status of the program
 * once it ends its execution.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /**
     * Toolbox Creation Steps:
     *  Create a Qt Widget to be the parent of the toolbox object
     *  Setup the user interface within that widget
     *  Show the widget
     */
    QWidget *toolboxParent;
    toolboxParent = new QWidget();
    toolboxParent->setParent(&w);

    Toolbox t;
    t.setupUi(toolboxParent);

    toolboxParent->show();

    return a.exec();
}
