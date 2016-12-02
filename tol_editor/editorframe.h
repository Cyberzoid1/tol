#ifndef EDITORFRAME_H

#define nrows 18
#define ncolumns 10
#include <QWidget>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>

#define EDITORFRAME_H


class EditorFrame
{
private:

    QPushButton * setupCell();
    QGridLayout * frameUI;
public:
    EditorFrame();
    QGridLayout * getGrid();
public slots:
    void cellColorHandler();

};

#endif // EDITORFRAME_H

