#ifndef MainWindow_M
#define MainWindow_M

#include "mainwindow.h"
#include "editorwindow.h"
#include <QApplication>

#endif  //MainWindow_M

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
