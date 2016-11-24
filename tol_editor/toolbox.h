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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QColorDialog>

/**
 * Toolbox class definition - this will be worked on
 * to make it an explicit QObject
 */
class Toolbox //: public QObject
{
   Q_OBJECT

public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *addFramesStart;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *addFramesEnd;
    QLabel *label_5;
    QPushButton *addFramesButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QSpinBox *removeFramesStart;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QSpinBox *removeFramesEnd;
    QLabel *label_11;
    QPushButton *removeFramesButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QSpinBox *copyFramesIndex;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QSpinBox *copyFramesStart;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QSpinBox *copyFramesEnd;
    QLabel *label_14;
    QPushButton *copyFramesButton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_15;
    QTimeEdit *currentTime;
    QLabel *label_23;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QTimeEdit *timeInterval;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_20;
    QLabel *label_18;
    QColorDialog *dialog;

    Toolbox(QWidget *parent = 0);
    ~Toolbox();

    void setupUi(QWidget *Toolbox);

    void setupUiTabs(QWidget *Toolbox);

    void setupUiMasterWidget();

    void setupUiLabels(QWidget *widget);

    void setupUiWidgets(QWidget *widget);

    void setupUiLayouts(QWidget *widget);

    void setupUiColorDialogue();

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
