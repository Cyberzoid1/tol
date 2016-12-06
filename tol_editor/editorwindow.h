/**
* @author Zachary Spence & Adonay Berhe
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
    explicit EditorWindow(QWidget *parent = 0);     // constructor
    ~EditorWindow();                                // destructor

    void setup( frameElement q, Frame data);
    QPushButton* createCell(RGB color);                      // create Cells
    void moveLeft( std::list<frameElement>::iterator q );
    void moveCent( std::list<frameElement>::iterator q );
    void moveRght( std::list<frameElement>::iterator q );

    void generateUiFrames(Animation *animation);
    void showFrames(std::vector<frameElement> frames, int currIndex);

public slots:
    void update();                                  // for the go-left UI button
    void lower();                                   // for the go-right UI Button
    //void upHandler();
    //void downHandler();
    //void rightHandler();
    //void leftHandler();
    //void duplicateHandler();
    //void addFrameHandler();
    //void clearFrameHandler();
    //void deleteFrameHandler();
    //void inputTanHandler();


private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;             //!< List containing the ordered sequence of frames in the UI
    std::list<frameElement>::iterator currFrame;    //!< An iterator for referencing the frame in listFrames that is current viewed
    int currIndex;

    QPushButton *currCells;                         //!< variable for adding current cells to the initial current window
    QPushButton *prevCells;                         //!< variable for adding cells to the initial previous window
    QPushButton *nxtCells;                          //!< variable for adding cells to the intital next window

    frameElement placeHolder;
};





#endif // EDITORWINDOW_H
