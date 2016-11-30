#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QFrame>
#include <frameelement.h>

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


public slots:
    void update();                                  // for the go-left UI button
    void lower();                                   // for the go-right UI Button

private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;
};



#endif // EDITORWINDOW_H
