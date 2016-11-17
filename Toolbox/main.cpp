#include "toolbox.h"
#include "colorwheel.h"
#include <QApplication>

//Attach Widgets to the UI
ColorWheel *cWheel;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolBox w;
    //Attach Widgets to the UI
    cWheel = new ColorWheel(ui->colorWheelWidget);
    cWheel->show();
    cWheel->size();
    w.show();

    return a.exec();
}
