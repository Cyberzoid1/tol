/**
* @class MainWindow
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"
#include "outputfile.h"
#include "toolbox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* windowFrame = new QWidget(this);
    animation = new Animation();
    toolbox = new Toolbox(windowFrame,animation);
    editor = new EditorWindow(windowFrame);

    windowFrame->setMinimumHeight(toolbox->height());
    windowFrame->setMinimumWidth(toolbox->width() + editor->width());

    hlayout = new QHBoxLayout;
    const int WINDOWPADDING = 70; // amount of padding to add between windows
    hlayout->addWidget(toolbox,WINDOWPADDING, Qt::AlignCenter);
    hlayout->addWidget(editor, Qt::AlignCenter);

    windowFrame->setLayout(hlayout);
    setCentralWidget(windowFrame);

    connect(toolbox,SIGNAL(updateUI()),this,SLOT(updateUI()));
    createActions();
    createMenus();

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * Slot for the 'Open' action in the 'File' menu. Reads in an animation
 * from a .tan2 file.
 */
void MainWindow::open()
{
    //obtain the name of the file to open from the dialog
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "",
                                                    tr("TAN Files (*.tan2)"));
    //read in the animation from the file and store it in the window's
    //data object
    animation = readInAnimation(filename.toStdString().c_str());
    //now that an animation has been read into the window, update the time interval
    //to the default value stored in the toolbox.
    QTime intvl = toolbox->timeInterval->time();
    int ms = (intvl.minute() * 60000) + (intvl.second() * 1000) + (intvl.msec());
    animation->setTimeInterval(ms);

    editor->setupFrames(animation, false);
}
/**
 * Slot for the 'Save' action in the 'File' menu. Writes the animation out
 * to the specified .tan2 file.
 */
void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Animation"),
                                                    "",
                                                    tr("TAN Files (*.tan2)"));
    writeFile(filename.toStdString(), animation);
}
/**
 * Create actions for the MainWindow's menu and toolbar.
 */
void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
}
/**
 * Create menus for the MainWindow's menu and toolbar.
 */
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
}
void MainWindow::updateUI()
{
    editor->updateFrameData();
    editor->refreshFrames();
}
/**
 * When the window is first opened, intialize the animation with a single
 * frame of default size. This will allow the user to start creating an
 * animation without reading in from a file first.
 * @return Void.
 */
void MainWindow::init()
{
    animation->addFrame(animation->getWidth(),
                        animation->getHeight(),
                        0);
    int defaultIntvl = 100;
    animation->setTimeInterval(defaultIntvl);
    editor->setupFrames(animation, true);
}
