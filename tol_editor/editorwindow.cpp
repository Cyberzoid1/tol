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
    connectSlots();
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
 * Setup the specified frameElement.
 * @param frame pointer to the UI frame
 * @param data Frame of data
 * @return Void.
 */
void EditorWindow::setup(frameElement *frame,Frame data)
{
    for( int i = 0; i < animation->getHeight(); i++ )
    {
        for( int j = 0; j < animation->getWidth(); j++ )
        {
            currCells = createCell(data.getCellColor(j, i));
            setButtonInfo(currCells, j, i);
            frame->grid->addWidget( currCells, i, j, 0 );
        }
    }
}
/**
 * Set the object name of the specified button to hold the row and column
 * in a comma-separated string.
 * @param button pointer to the button to update
 * @param row corresponds to the x value in the grid for the button
 * @param col corresponds to the y value in the grid for the button
 * @return void
 */
void EditorWindow::setButtonInfo(QPushButton *button, int row, int col)
{
    QString rowIndex = QString::number(row);
    QString colIndex = QString::number(col);
    QString rowStr = ((row < 10) ? "0" + rowIndex : rowIndex);
    QString colStr = ((col < 10) ? "0" + colIndex : colIndex);
    button->setObjectName(rowStr + "," + colStr);
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
 * @param cell pointer to a button in the grid
 * @param color object containing the RGB value to update the cell to
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
 * @param frame pointer to the UI frame
 * @param data Frame of data
 * @return Void.
 */
void EditorWindow::updateCells(frameElement *frame, Frame data)
{
    for (int i = 0; i < animation->getHeight(); i++){
        for (int j = 0; j < animation->getWidth(); j++){
            QLayoutItem *cell = frame->grid->itemAtPosition(i, j);
            QWidget *widg = cell->widget();
            QPushButton *button = dynamic_cast<QPushButton*>(widg);
            setCellColor(button, data.getCellColor(j, i));
        }
    }
}
/**
 * Using the animation read in from the file, setup the first few frames
 * in the UI of the editor window. Also, handle enabling/disabling the
 * navigation buttons.
 * @param animation pointer to the animation read in from a file
 * @param initial indicates whether this is the inital setup or not
 * @return Void.
 */
void EditorWindow::setupFrames(Animation *animation, bool initial)
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
        if (initial){
            setup(uiFrames[i], dataFrames[i]);
            uiFrames[i]->self = uiContainers[i];
            uiFrames[i]->self->setLayout(uiFrames[i]->grid);
        }
        else{
            updateCells(uiFrames[i], dataFrames[i]);
        }
    }

    this->currFrame = frames.begin();
    animation->setCurrentFrame(&(*(this->currFrame)));
    this->currIndex = 0;

    updateLocLabel();
    toggleNavButtons();
}
/**
 * Connect the signals and slots for the various UI buttons.
 * @return Void.
 */
void EditorWindow::connectSlots()
{
    connect(ui->GoLeftIcon, SIGNAL(clicked(bool)), this, SLOT(goLeft()));
    connect(ui->GoRightIcon, SIGNAL(clicked(bool)), this, SLOT(goRight()));
    connect(ui->DuplicateIcon, SIGNAL(clicked(bool)), this, SLOT(duplicateHandler()));
    connect(ui->NewFrameIcon, SIGNAL(clicked(bool)), this, SLOT(addFrameHandler()));
    connect(ui->DeleteFrameIcon, SIGNAL(clicked(bool)), this, SLOT(deleteFrameHandler()));
    connect(ui->upDupIcon, SIGNAL(clicked(bool)), this, SLOT(shiftHandler()));
    connect(ui->DownDupIcon, SIGNAL(clicked(bool)), this, SLOT(shiftHandler()));
    connect(ui->LeftDupIcon, SIGNAL(clicked(bool)), this, SLOT(shiftHandler()));
    connect(ui->RightDupIcon, SIGNAL(clicked(bool)), this, SLOT(shiftHandler()));
}

/**
 * Toggle navigation buttons to prevent the user from transitioning
 * beyond the start or end of the list of frames.
 * @return Void.
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
/**
 * Helper method to update the list of frames and pointer to the current frame.
 * @return void.
 */
void EditorWindow::updateFrameData()
{
    this->frames = animation->getFrames();
    this->currFrame = std::next(this->frames.begin(), currIndex);
    animation->setCurrentFrame(&(*this->currFrame));
}
/**
 * Update the locationLabel so that it contains: "current index/number of frames"
 * @return Void.
 */
void EditorWindow::updateLocLabel()
{
    ui->locationLabel->setText(QString::number(this->currIndex)+
                               "/" +
                               QString::number(frames.size() - 1));
}
/**
 * Called for updating the UI after a frame has been removed. Since the current
 * index and frame has been adjusted prior to calling, simply refresh the
 * UI frames in place in the editor.
 * @return Void.
 */
void EditorWindow::refreshFrames()
{
    int width = animation->getWidth();
    int height = animation->getHeight();
    Frame newPrev(width, height),
          newNext(width, height);

    if (currIndex - 1 > 0)
        newPrev = *std::next(currFrame, -1);
    if (currIndex + 1 < frames.size())
        newNext = *std::next(currFrame, 1);

    std::vector<Frame> activeFrames = {
        newPrev,
        *currFrame,
        newNext
    };

    for (int i = 0; i < activeFrames.size(); i++){
        updateCells(uiFrames[i], activeFrames[i]);
    }
    animation->setCurrentFrame(&(*(currFrame)));
    toggleNavButtons();
    updateLocLabel();
}

/**
 * This is the slot for when the "Go-Left" Button is clicked
 * by the user.
 * @return Void.
 */
void EditorWindow::goLeft()
{
    int width = animation->getWidth();
    int height = animation->getHeight();
    Frame newPrev(width, height),
          newCurr(width, height);

    if (currIndex - 2 > 0)
        newPrev = *std::next(currFrame, -2);
    if (currIndex - 1 >= 0)
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
    updateLocLabel();
}
/**
 * This is the slot used when the user clicks the "Go-Right" button.
 * @return Void.
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
    updateLocLabel();
}
/**
 * Called when a cell in a frame is clicked. Changes the color of that cell
 * in the UI and backend data to the last color selected from the toolbox.
 * @return Void.
 */
void EditorWindow::handleCellColor()
{
    QPushButton *temp = qobject_cast<QPushButton*>(sender());
    setCellColor(temp, animation->getLastColor());
    Frame *currFrame = &(*this->currFrame);
    //the (row,col) position is stored in the qpushbutton's object name
    //extract those values for setting the corresponding cell's color
    QString index = temp->objectName();
    QString row = index.mid(0, 2);
    QString col = index.mid(3, 2);

    currFrame->setCellColor(row.toInt(), col.toInt(), animation->getLastColor());
    animation->setFrames(this->frames);
}
/**
 * Called when the 'up' button is clicked. Duplicates the current frame, shifts its
 * rows up, updates the list of frames, and then transitions to the shifted frame.
 * @return Void.
 */
void EditorWindow::shiftHandler()
{
    int dir = 0;
    QString name = sender()->objectName();
    if (name == "upDupIcon")
        dir = 0;
    else if (name == "DownDupIcon")
        dir = 1;
    else if (name == "LeftDupIcon")
        dir = 2;
    else if (name == "RightDupIcon")
        dir = 3;
    animation->shiftFrame(*(this->currFrame), dir);
    updateFrameData();
    goRight();
}
/**
 * Called when the 'duplicate' button is clicked. Duplicates the current frame,
 * updates the list of frames and currFrame pointer, and then transitions to the new,
 * duplicate frame.
 * @return Void.
 */
void EditorWindow::duplicateHandler()
{
    animation->duplicateFrame(*(this->currFrame));
    updateFrameData();
    goRight();
}
/**
 * Called when the 'add' button is clicked. Adds a new, blank frame after
 * the current frame, updates the list of frames, and then transitions to the new
 * frame.
 * @return Void.
 */
void EditorWindow::addFrameHandler()
{
    animation->addFrame(animation->getWidth(),
                        animation->getHeight(),
                        this->currIndex+1);
    updateFrameData();
    goRight();
}
/**
 * Called when the 'delete' button is clicked. Removes the current frame, updates
 * the list of frames, and transitions to the previous frame.
 * @return Void.
 */
void EditorWindow::deleteFrameHandler()
{
    animation->removeFrame(this->currIndex);
    if (this->currIndex != 0)
        this->currIndex--;
    updateFrameData();
    refreshFrames();
}

