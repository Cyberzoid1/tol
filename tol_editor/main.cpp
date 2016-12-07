#include "mainwindow.h"
#include "animation.h"
#include "input.h"
#include "outputfile.h"
#include "toolbox.h"
#include "editorwindow.h"
#include <QApplication>

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
    MainWindow mainwindow;
    mainwindow.show();

    return a.exec();
}
