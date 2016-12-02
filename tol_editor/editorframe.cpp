#include "editorframe.h"

EditorFrame::EditorFrame()
{
    QPushButton * cell;
    frameUI = new QGridLayout();

    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncolumns; j++)
        {
            cell = setupCell();
            frameUI->addWidget(cell,i,j,0);
        }
    }
}


QPushButton * EditorFrame::setupCell()
{
    QPushButton * n = new QPushButton();
    n->setStyleSheet("border: 1px solid;" "background-color: gray");
    return n;
}

QGridLayout * EditorFrame::getGrid()
{
    return frameUI;
}
