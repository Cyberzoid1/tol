#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);     // constructor
    ~EditorWindow();                                // destructor
    struct frameElement                             // nodes for the list of ui frames
    {
        QFrame* self;                               // the frame belonging to the node
        frameElement *prev;                               // the previous frame
        frameElement *next;                               // the next frame
    };
    void setup();

public slots:
    void update();
    void lower();

private:
    Ui::EditorWindow *ui;
};

#endif // EDITORWINDOW_H
