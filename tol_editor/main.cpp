#ifndef MainWindow_M
#define MainWindow_M

#include "mainwindow.h"
#include "editorwindow.h"
#include <QApplication>
#include "animation.h"
#include "input.h"
#include "outputfile.h"

#endif  //MainWindow_M



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
    EditorWindow * editorwindow = new EditorWindow(&mainwindow);
    editorwindow->SetTableFrames();
    mainwindow.show();
    editorwindow -> show();

    return a.exec();
}
