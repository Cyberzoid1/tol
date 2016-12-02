#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include "editorframe.h"
#include <list>
#include <iterator>
#include <QtAlgorithms>


namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();
    QPushButton * createCell();

public slots:
//    void upHandler();
//    void downHandler();
//    void rightHandler();
//    void leftHandler();
//    void duplicateHandler();
//    void addFrameHandler();
//    void clearFrameHandler();
//    void deleteFrameHandler();
//    void inputTanHandler();


private:
    Ui::EditorWindow *ui;
//    EditorFrame *eFrame;
    std::list<EditorFrame> frameList;



};



#endif // EDITORWINDOW_H
