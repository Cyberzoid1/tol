#include "mainwindow.h"
#include "animation.h"
#include "input.h"
#include "outputfile.h"
#include "toolbox.h"
#include <QApplication>
#include <QWidget>

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
    Toolbox *t = new Toolbox(&w);

    return a.exec();
}
