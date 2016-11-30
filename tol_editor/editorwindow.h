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

    class cell
    {
        int red;
        int green;
        int blue;
        QWidget* self;
public:
        void setColor( int r, int g, int b );
    };


    struct frameElement                             // nodes for the list of ui frames
    {
        QFrame* self;                               // the frame belonging to the node

        bool isCurrent;                             // if the node is the current frame being viewed
        cell cellGrid[8][20];                       // array of cells for the grid
        int name;                                   // the number identifying the frame
        int width;                                  // the width of the frame
        int height;                                 // the height of the frame
    };


    void setup();

public slots:
    void update();                                  // for the go-left UI button
    void lower();                                   // for the go-right UI Button

private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;
};



#endif // EDITORWINDOW_H
