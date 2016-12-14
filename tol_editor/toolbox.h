/**
* @author Matthew Holman and Domanic Welker
* @date 11/17/2016
* @class Toolbox
* @brief This is the header file that defines the Toolbox class.
* @details This file contains the definitions of Toolbox class used
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
#include <QMainWindow>
#include <QObject>
#include <QTime>
#include <QColorDialog>
#include <QColor>
#include <QFont>
#include <QTextEdit>
#include <QLineEdit>
#include "animation.h"

/**
 * Toolbox class definition - this will be worked on
 * to make it an explicit QObject
 */
class Toolbox : public QWidget
{
   Q_OBJECT

public:
    /**
     * Font Widgets
     */
    QFont toolBoxFont;

    /**
     * Tab Widgets
     */
    QTabWidget *tabParent;
    QWidget *tabColor;
    QWidget *tabEdit;
    QWidget *tabMusic;

    /**
     * Master Control Widgets
     */
    QWidget *widget;
    QWidget *musicWidget;

    /**
     * Master Layouts
     */
    QVBoxLayout *loMasterLayout;
    QVBoxLayout *loMusicMasterLayout;

    /**
     * Music Widgets
     */
    QHBoxLayout *loMusicFileName;
    QVBoxLayout *loMusicFileNameText;
    QVBoxLayout *loMusicFileNameButton;
    QLabel *lblMusicFileName;
    QLineEdit *txtMusicFileName;
    QPushButton *btnMusicFileName;

    /**
     * Add Frame Widgets
     */
    QHBoxLayout *loAddFrames;
    QVBoxLayout *loAddFramesStart;
    QLabel *lblAddFramesStart;
    QSpinBox *addFramesStart;
    QLabel *lblAddFramesStartSpacer;
    QVBoxLayout *loAddFramesEnd;
    QLabel *lblAddFramesEnd;
    QSpinBox *addFramesEnd;
    QLabel *lblAddFramesEndSpacer;
    QPushButton *addFramesButton;

    /**
     * Remove Frame Widgets
     */
    QHBoxLayout *loRemoveFrames;
    QVBoxLayout *loRemoveFramesFirst;
    QLabel *lblRemoveFramesFirst;
    QSpinBox *removeFramesStart;
    QLabel *lblRemoveFramesFirstSpacer;
    QVBoxLayout *loRemoveFramesLast;
    QLabel *lblRemoveFramesLast;
    QSpinBox *removeFramesEnd;
    QLabel *lblRemoveFramesLastSpacer;
    QPushButton *removeFramesButton;

    /**
     * Copy Frame Widgets
     */
    QHBoxLayout *loCopyFrames;
    QVBoxLayout *loCopyFramesFrame;
    QLabel *lblCopyFramesFrame;
    QSpinBox *copyFramesIndex;
    QLabel *lblCopyFramesFrameSpacer;
    QVBoxLayout *loCopyFramesStart;
    QLabel *lblCopyFramesStart;
    QSpinBox *copyFramesStart;
    QLabel *lblCopyFramesStartSpacer;
    QVBoxLayout *loCopyFramesEnd;
    QLabel *lblCopyFramesEnd;
    QSpinBox *copyFramesEnd;
    QLabel *lblCopyFramesEndSpacer;
    QPushButton *copyFramesButton;

    /**
     * Timing Widgets
     */
    QHBoxLayout *loTiming;
    QVBoxLayout *loTimingCurrentTime;
    QLabel *lblTimingCurrentTime;
    QTimeEdit *currentTime;
    QLabel *lblTimingCurrentTimeSpacer1;
    QLabel *lblTimingCurrentTimeSpacer2;
    QLabel *lblTimingCurrentTimeSpacer3;
    QLabel *lblTimingCurrentTimeSpacer4;
    QVBoxLayout *loTimingTimeInterval;
    QLabel *lblTimingTimeInterval;
    QTimeEdit *timeInterval;
    QLabel *lblTimingTimeIntervalSpacer1;
    QLabel *lblTimingTimeIntervalSpacer2;
    QLabel *lblTimingTimeIntervalSpacer3;
    QLabel *lblTimingTimeIntervalSpacer4;

    /**
     * Color Dialog Box Widget
     */
    QColorDialog *colorDialog;

    Animation *animPtr;

    /**
     * Toolbox Constructor/ Destructor Functions
     */
    explicit Toolbox(QWidget *parent = 0, Animation *aPtr = 0);
    ~Toolbox();

    /**
     * Toolbox Setup Functions
     */
    void setupUi(QWidget *Toolbox);

    void setupUiFont();

    void setupUiTabs(QWidget *Toolbox);

    void setupUiMasterWidget();

    void setupUiLabels(QWidget *widget);

    void setupUiLabelsMusic(QWidget *musWidget);

    void setupUiWidgets(QWidget *widget);

    void setupUiWidgetsMusic(QWidget *musWidget);

    void setupUiLayouts(QWidget *widget);

    void setupUiLayoutsMusic(QWidget *musWidget);

    void setupUiColorDialogue();

    void retranslateUi(QWidget *Toolbox);

signals:
    void updateUI();

private:
    int addFramesInsertionIndex = 0;
    int addFramesNumberOfFrames = 0;
    int removeFramesDeletionIndex = 0;
    int removeFramesNumberOfFrames = 0;
    int copyFramesInsertionIndex = 0;
    int copyFramesStartIndex = 0;
    int copyFramesEndIndex = 0;

public slots:

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

    void on_currentTime_timeChanged(QTime timeVal);

    void on_timeInterval_timeChanged(QTime timeVal);

    void on_colorDialog_currentColorChanged(QColor colorVal);

    void on_btnMusicFileName_clicked();
};

#endif // TOOLBOX_H
