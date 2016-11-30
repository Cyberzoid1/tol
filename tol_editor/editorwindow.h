#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QPushButton>

#define nrows 18
#define ncolumns 8

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();
    QPushButton * createCell();


private:
    Ui::EditorWindow *ui;
    QPushButton *currCells;
    QPushButton *prevCells;
    QPushButton *nxtCells;


};


#endif // EDITORWINDOW_H
