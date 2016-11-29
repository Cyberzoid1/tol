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

        bool isCurrent;                             // if the node is the current frame being viewed

        int name;
        int width;
        int height;
    };

    void setup();

public slots:
    void update();
    void lower();

private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;
};

#endif // EDITORWINDOW_H
