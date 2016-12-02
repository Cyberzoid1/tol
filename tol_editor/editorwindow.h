#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QFrame>
#include <frameelement.h>
#include <QPushButton>

#define nrows 20
#define ncolumns 8

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);     // constructor
    ~EditorWindow();                                // destructor

    void setup();
    QPushButton* createCell();                      // create Cells

public slots:
    void update();                                  // for the go-left UI button
    void lower();                                   // for the go-right UI Button

private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;             // List of frames
    std::list<frameElement>::iterator currFrame;    // An iterator to always point to the first frame

    QPushButton *currCells;                         // for adding current cells to the initial current window
    QPushButton *prevCells;                         // for adding cells to the initial previous window
    QPushButton *nxtCells;                          // for adding cells to the intital next window

};





#endif // EDITORWINDOW_H
