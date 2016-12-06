/**
* @class EditorWindow
*/


#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <list>
#include <iterator>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QtAlgorithms>

/**
 * @brief EditorWindow::EditorWindow
 * @param parent
 * The constructor sets the UI,
 * fills the list of frameElements,
 * and creates all the initial values
 */


EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    prevFrameElement = new frameElement;
    currFrameElement = new frameElement;
    nextFrameElement = new frameElement;

    currIndex = 0;
    ui->GoLeftIcon->setEnabled(false);
    ui->GoRightIcon->setEnabled(false);
}

/**
 * @brief EditorWindow::~EditorWindow
 */

EditorWindow::~EditorWindow()
{
    delete ui;
}

/**
 * @brief EditorWindow::update
 * This is the slot for when the
 * "Go-Right" Button is clicked
 * by the user
 */

void EditorWindow::update()
{

}


/**
 * @brief EditorWindow::lower
 * This is the slot used when the user
 * clicks the "Go-Right" button.
 */

void EditorWindow::lower()
{
    updateCells(currFrameElement, *currFrame);
}

void EditorWindow::setup(frameElement *frame,Frame data)
{

    for( int i = 0; i < animation->getWidth(); i++ )
    {
        for( int j = 0; j < animation->getHeight(); j++ )
        {
            currCells = createCell(data.getCellColor(i, j));
            frame->grid->addWidget( currCells, i, j, 0 );
        }
    }
}
/**
 * @brief EditorWindow::createCell
 * this creates a new QPushbutton with
 * our own style.
 * @param color RGB object containing the color value
 * @return a pointer to a QPushButton, as
 * that is the implementation of our cells
 * in the UI
 */
QPushButton* EditorWindow::createCell(RGB color)                                         // Definition of the createCell function
{
    QPushButton* newCell;                                                       // create the new cell
    newCell = new QPushButton;                                                  // assign it some memory
    setCellColor(newCell, color);
    return newCell;                                                             // return it
}
void EditorWindow::setCellColor(QPushButton *cell, RGB color)
{
    QString colorStr = "background-color: rgb(" +
            QString::number(color.getRed()) +
            "," +
            QString::number(color.getGreen()) +
            "," +
            QString::number(color.getBlue()) +
            ");";
    cell->setStyleSheet( "border: 1px solid;" + colorStr);
}
void EditorWindow::updateCells(frameElement *frame, Frame data)
{
    for (int i = 0; i < animation->getWidth(); i++){
        for (int j = 0; j < animation->getHeight(); j++){
            QLayoutItem *cell = frame->grid->itemAtPosition(i, j);
            setCellColor((QPushButton*)cell, data.getCellColor(i, j));
        }
    }
}

void EditorWindow::setupFrames(Animation *animation)
{
    this->animation = animation;
    std::vector<QFrame*> uiContainers = {
        ui->previousFrame,
        ui->currentFrame,
        ui->nextFrame
    };
    std::vector<frameElement*> uiFrames = {
        prevFrameElement,
        currFrameElement,
        nextFrameElement
    };
    Frame prev(animation->getWidth(), animation->getHeight());
    std::vector<Frame> dataFrames = {
        prev,
        *animation->getFrames().begin()
    };
    Frame next = prev;
    if (animation->getNumFrames() > 1)
        next = *std::next(animation->getFrames().begin(), 1);
    dataFrames.push_back(next);

    for (int i = 0; i < uiFrames.size(); i++){
        setup(uiFrames[i], dataFrames[i]);
        uiFrames[i]->self = uiContainers[i];
        uiFrames[i]->self->setLayout(uiFrames[i]->grid);
    }
}
