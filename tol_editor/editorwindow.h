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


namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);     // constructor
    ~EditorWindow();                                // destructor

//Methods
    void setup();
    void setCurrentFrame();
    QPushButton* createCell();                      // create Cells
	void moveLeft( std::list<frameElement>::iterator q );
    void moveCent( std::list<frameElement>::iterator q );
    void moveRght( std::list<frameElement>::iterator q );



public slots:
    void update();                                  // for the go-left UI button
    void lower();                                   // for the go-right UI Button

private:
    Ui::EditorWindow *ui;
    std::list<frameElement> listFrames;             //!< List containing the ordered sequence of frames in the UI
    std::list<frameElement>::iterator currFrame;    //!< An iterator for referencing the frame in listFrames that is current viewed

};





#endif // EDITORWINDOW_H
