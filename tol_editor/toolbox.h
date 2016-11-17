/**
 * CS 383
 * Group #4
 * Created: 11/17/2016
 *
 * This file contains the definitions of Toolbox class used
 * to hold the color picker and various other tools.
 */

#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QColorDialog>
#include <QObject>
#include <QWidget>

/**
 * Toolbox class definition - this will be worked on
 * to make it an explicit QObject
 */
class Toolbox //: public QObject
{
   // Q_OBJECT

public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *addFramesStart;
    QSpinBox *addFramesEnd;
    QPushButton *addFramesButton;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *copyFramesStart;
    QSpinBox *copyFramesEnd;
    QHBoxLayout *horizontalLayout;
    QSpinBox *copyFramesIndex;
    QPushButton *copyFramesButton;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *removeFramesStart;
    QSpinBox *removeFramesEnd;
    QPushButton *removeFramesButton;
    QColorDialog *dialog;

    void setupUi(QWidget *Toolbox);

    void retranslateUi(QWidget *Toolbox);

signals:
    void on_addFramesEnd_changeValue(int arg1);

    void on_addFramesStart_changeValue(int arg1);

    void on_addFramesButton_click();

    void on_removeFramesStart_changeValue(int arg1);

    void on_removeFramesEnd_changeValue(int arg1);

    void on_removeFramesButton_click();

    void on_copyFramesStart_changeValue(int arg1);

    void on_copyFramesEnd_changeValue(int arg1);

    void on_copyFramesIndex_changeValue(int arg1);

    void on_copyFramesButton_click();

    void changeColor();

private slots:

    void on_addFramesEnd_valueChanged(int arg1);

    void on_addFramesStart_valueChanged(int arg1);

    void on_addFramesButton_clicked();

    void on_removeFramesStart_valueChanged(int arg1);

    void on_removeFramesEnd_valueChanged(int arg1);

    void on_removeFramesButton_clicked();

    void on_copyFramesStart_valueChanged(int arg1);

    void on_copyFramesEnd_valueChanged(int arg1);

    void on_copyFramesIndex_valueChanged(int arg1);

    void on_copyFramesButton_clicked();

    void colorChanged();
};

#endif // TOOLBOX_H
