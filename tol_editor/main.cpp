#include "mainwindow.h"
#include "animation.h"
#include "input.h"
#include "outputfile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
