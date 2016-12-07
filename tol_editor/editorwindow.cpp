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

    uiContainers = {
        ui->previousFrame,
        ui->currentFrame,
        ui->nextFrame
    };
    for (int i = 0; i < 3; i++)
        uiFrames.push_back(new frameElement);

    currIndex = 0;
    connect(ui->GoLeftIcon, SIGNAL(clicked(bool)), this, SLOT(goLeft()));
    connect(ui->GoRightIcon, SIGNAL(clicked(bool)), this, SLOT(goRight()));
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
 * This is the slot for when the
 * "Go-Left" Button is clicked
 * by the user
 */
void EditorWindow::goLeft()
{
    int width = animation->getWidth();
    int height = animation->getHeight();
    Frame newPrev(width, height),
          newCurr(width, height);

    if (currIndex - 2 > 0)
        newPrev = *std::next(currFrame, -2);
    if (currIndex - 1 > 0)
        newCurr = *std::next(currFrame, -1);

    std::vector<Frame> activeFrames = {
        newPrev,
        newCurr,
        *currFrame
    };

    for (int i = 0; i < activeFrames.size(); i++){
        updateCells(uiFrames[i], activeFrames[i]);
    }
    currFrame--;
    animation->setCurrentFrame(&(*(currFrame)));
    currIndex--;
    toggleNavButtons();
}


/**
 * This is the slot used when the user
 * clicks the "Go-Right" button.
 */
void EditorWindow::goRight()
{
    int width = animation->getWidth();
    int height = animation->getHeight();
    Frame newCurr(width, height),
          newNext(width, height);

    if (frames.size() > 1 &&
            currIndex + 1 < frames.size())
        newCurr = *std::next(currFrame, 1);
    if (frames.size() > 2 &&
            currIndex + 2 < frames.size())
        newNext = *std::next(currFrame, 2);

    std::vector<Frame> activeFrames = {
        *currFrame,
        newCurr,
        newNext
    };

    for (int i = 0; i < activeFrames.size(); i++){
        updateCells(uiFrames[i], activeFrames[i]);
    }
    currFrame++;
    animation->setCurrentFrame(&(*(currFrame)));
    currIndex++;
    toggleNavButtons();
}
/**
 * Setup the specified frameElement.
 * @param frame
 * @param data
 */
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
    connect(newCell, SIGNAL(clicked()), this, SLOT(handleCellColor()));
    return newCell;                                                             // return it
}
/**
 * Set the color of a cell in a frame to the specified color.
 * @param cell
 * @param color
 */
void EditorWindow::setCellColor(QPushButton *cell, RGB color)
{
    QColor qcolor(color.getRed(), color.getGreen(), color.getBlue());
    QPalette pal = cell->palette();
    pal.setColor(QPalette::Button, qcolor);
    cell->setAutoFillBackground(true);
    cell->setPalette(pal);
    cell->setFlat(true);
    cell->update();
}
/**
 * Update the colors of the cells in the specified frame after a transition.
 * @param frame
 * @param data
 */
void EditorWindow::updateCells(frameElement *frame, Frame data)
{
    for (int i = 0; i < animation->getWidth(); i++){
        for (int j = 0; j < animation->getHeight(); j++){
            QLayoutItem *cell = frame->grid->itemAtPosition(i, j);
            QWidget *widg = cell->widget();
            QPushButton *button = dynamic_cast<QPushButton*>(widg);
            setCellColor(button, data.getCellColor(i, j));
        }
    }
}
/**
 * Using the animation read in from the file, setup the first few frames
 * in the UI of the editor window. Also, handle enabling/disabling the
 * navigation buttons.
 * @param animation
 */
void EditorWindow::setupFrames(Animation *animation)
{
    this->frames = animation->getFrames();
    this->animation = animation;

    Frame prev(animation->getWidth(), animation->getHeight());
    std::vector<Frame> dataFrames = {
        prev,
        *frames.begin()
    };
    Frame next = prev;
    if (animation->getNumFrames() > 1)
        next = *std::next(frames.begin(), 1);
    dataFrames.push_back(next);

    for (int i = 0; i < uiFrames.size(); i++){
        setup(uiFrames[i], dataFrames[i]);
        uiFrames[i]->self = uiContainers[i];
        uiFrames[i]->self->setLayout(uiFrames[i]->grid);
    }
    this->currFrame = frames.begin();
    animation->setCurrentFrame(&(*(this->currFrame)));
    this->currIndex = 0;

    toggleNavButtons();
}
/**
 * Toggle navigation buttons to prevent the user from transitioning
 * beyond the start or end of the list of frames.
 */
void EditorWindow::toggleNavButtons()
{
    if (this->currIndex > 0)
        ui->GoLeftIcon->setEnabled(true);
    else
        ui->GoLeftIcon->setEnabled(false);
    //subtract 1 from size to account for zero-based indexing
    if (this->currIndex < (frames.size() - 1))
        ui->GoRightIcon->setEnabled(true);
    else
        ui->GoRightIcon->setEnabled(false);
}

void EditorWindow::handleCellColor()
{
    QPushButton * temp = qobject_cast<QPushButton*>(sender());
    setCellColor(temp, animation->getLastColor());
    return;
}
