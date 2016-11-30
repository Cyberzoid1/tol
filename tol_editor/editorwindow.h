#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QPushButton>

#define nrows 20
#define ncolumns 10


namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

    void setFrames(/* <list>*/);

private:
    Ui::EditorWindow *ui;
    QPushButton *currCells;
    QPushButton *prevCells;
    QPushButton *nxtCells;

};

QPushButton {
    border: 2px solid #8f8f91;
    border-radius: 6px;
    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                      stop: 0 #f6f7fa, stop: 1 #dadbde);
    min-width: 80px;
}


#endif // EDITORWINDOW_H
