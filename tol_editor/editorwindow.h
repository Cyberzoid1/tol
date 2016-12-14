/**
* @author Zachary Spence & Adonay Berhe & Trevor Morse
* @date 11/18/2016
* @class EditorWindow
* @brief This is the header file for the EditorWindow class.
* @details This class is utilized to setup the editing window of
* the UI in the Tower of Light's project as well as a list of @frameElement
* nodes and the rules defining their setup and movement in the window.
*/

#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QFrame>
#include <frameelement.h>
#include <QPushButton>
#include <list>
#include <iterator>
#include "RGB.h"
#include "animation.h"

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

    void setup(frameElement *frame, Frame data);
    void setButtonInfo(QPushButton *button, int row, int col);
    QPushButton* createCell(RGB color);
    void setCellColor(QPushButton *cell, RGB color);
    void updateCells(frameElement *frame, Frame data);

    void setupFrames(Animation *animation, bool initial);

    void connectSlots();
    void toggleNavButtons();
    void updateFrameData();
    void updateLocLabel();

    void refreshFrames();

public slots:
    void goLeft();
    void goRight();
    void handleCellColor();
    void shiftHandler();
    void duplicateHandler();
    void addFrameHandler();

    void deleteFrameHandler();

private:
    Ui::EditorWindow *ui; //!< pointer to the EditorWindow UI generated by Qt

    std::vector<QFrame*> uiContainers; //!< vector of frame containers for the EditorWindow
    std::vector<frameElement*> uiFrames; //!< vector of frameElement pointers to store active frames

    Animation *animation; //!< reference to the animation object as read in from a file
    std::list<Frame> frames; //!< list of Frames stored in the animation object
    std::list<Frame>::iterator currFrame; //!< pointer to the current Frame
    int currIndex; //!< index of the current Frame in the overall list

    QPushButton *currCells; //!< variable for adding current cells to the initial current window
};
#endif // EDITORWINDOW_H
