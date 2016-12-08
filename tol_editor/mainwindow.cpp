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
    animation = new Animation();
    ui->setupUi(this);

    outerWrapper = new QWidget;
    hlayout = new QHBoxLayout;
    tbParent = new QWidget;
    toolbox = new Toolbox(tbParent, animation);
    edParent = new QWidget;
    editor = new EditorWindow(edParent);

    tbParent->setMaximumWidth(toolbox->width());
    edParent->setMaximumWidth(editor->width());
    hlayout->setSpacing(0);
    hlayout->setMargin(0);
    hlayout->addWidget(tbParent);
    hlayout->addWidget(edParent);

    outerWrapper->setLayout(hlayout);

    this->setCentralWidget(outerWrapper);
    this->setMinimumWidth(toolbox->width() + editor->width());
    this->setMinimumHeight(editor->height());

    createActions();
    createMenus();
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
    *animation = readInAnimation(filename.toStdString().c_str());
    //now that an animation has been read into the window, update the time interval
    //to the default value stored in the toolbox.
    QTime intvl = toolbox->timeInterval->time();
    int ms = (intvl.minute() * 60000) + (intvl.second() * 1000) + (intvl.msec());
    animation->setTimeInterval(ms);

    editor->setupFrames(animation);
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
