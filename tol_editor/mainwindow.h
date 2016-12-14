/**
* @author ...
* @date 11/20/2016
* @class MainWindow
* @brief This is the header file defining the MainWindow Class
* @details This header file defines the MainWindow class which is object in
* the Tower Lights Animator that contains all of the different User Interface
* functionality as well as the different objects that make up the animation itself.
*/

#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include "animation.h"
#include "toolbox.h"
#include "editorwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Animation *animation; //!< Reference to animation storage object

private slots:
    void open();
    void save();
    void updateUI();

private:
    Ui::MainWindow *ui; //!< Reference to the internal UI object

    Toolbox *toolbox; //!< Reference to toolbox object
    EditorWindow *editor; //!< Reference to editor object
    QWidget *outerWrapper; //!< Reference to wrapper element that serves as MainWindow's central widget
    QHBoxLayout *hlayout; //!< Reference to horizontal layout that contains the toolbox and editor
    QWidget *tbParent; //!< Reference to widget that acts as the toolbox's parent
    QWidget *edParent; //!< Reference to widget that acts as the editor's parent

    QMenu *fileMenu; //!< Reference to the MainWindow's file menu
    QAction *openAct; //!< Reference to the open action in the file menu
    QAction *saveAct; //!< Reference to the save action in the file menu

    void createActions(); //!< Helper method to instantiate actions
    void createMenus(); //!< Helper method to instantiate menus

    void init();

    Toolbox *tBox; //!< Toolbox object

/*protected:
    Animation *animation; //!< Reference to animation storage object
    Toolbox *tBox; //!< Toolbox object*/
};

#endif // MAINWINDOW_H
