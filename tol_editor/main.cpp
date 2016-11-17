#include "mainwindow.h"
#include "editorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwindow;
//    EditorWindow * editorwindow = new EditorWindow(&mainwindow);
    mainwindow.show();
//    editorwindow -> show();

    return a.exec();
}
