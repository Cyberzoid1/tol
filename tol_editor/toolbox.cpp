/**
 * CS 383
 * Group #4
 * Created: 11/17/2016
 *
 * This file contains the implimentations of the Toolbox class used
 * to hold the color picker widget and other tools.
 */

/**
 * @class Toolbox
 */

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
#include <QTime>
#include <QRect>
#include <QFont>
#include <QLabel>
#include "toolbox.h"
#include "animation.h"
#include "mainwindow.h"

/**
 * Constructor that sets up the User interface elements according to the
 * defined layout in the Qt Creator editor
 * @param A pointer to the parent widget of the toolbox
 * @param A pointer to the animation class of the parent
 */
Toolbox::Toolbox(QWidget *parent, Animation *aPtr){
    animPtr = aPtr;
    setupUi(parent);
}

Toolbox::~Toolbox(){

}

/**
 * Sets up the entire graphical user interface for the toolbox
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::setupUi(QWidget *parent)
{
    if (parent->objectName().isEmpty()){
        parent->setObjectName(QStringLiteral("Toolbox"));
    }

    setupUiTabs(parent);

    setupUiColorDialogue();

    setupUiMasterWidget();

    setupUiLabels(widget);

    setupUiLabelsMusic(musicWidget);

    setupUiWidgets(widget);

    setupUiWidgetsMusic(musicWidget);

    setupUiLayouts(widget);

    setupUiLayoutsMusic(musicWidget);

    retranslateUi(parent);

    tabParent->move(0, 50);
} // setupUi

/**
 * Used to create the tab widget in the toolbox
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::setupUiTabs(QWidget *Toolbox){
    tabParent = new QTabWidget(Toolbox);
    tabParent->setObjectName(QStringLiteral("tabParent"));
    tabParent->setGeometry(QRect(0, 0, Toolbox->width(), Toolbox->height()));
    tabParent->setAutoFillBackground(false);
    tabParent->show();

    tabColor = new QWidget();
    tabColor->setObjectName(QStringLiteral("tabColor"));
    tabColor->setGeometry(QRect(0,0,tabParent->width(), tabParent->height()));
    tabParent->addTab(tabColor, QString());

    tabEdit = new QWidget();
    tabEdit->setObjectName(QStringLiteral("tabEdit"));
    tabEdit->setGeometry(QRect(0,0,tabParent->width(), tabParent->height()));
    tabParent->addTab(tabEdit, QString());

    tabMusic = new QWidget();
    tabMusic->setObjectName(QStringLiteral("tabMusic"));
    tabMusic->setGeometry(QRect(0,0,tabParent->width(), tabParent->height()));
    tabParent->addTab(tabMusic,QString());
}

/**
 * Used to create the widget that the editing portion of the toolbox is made in
 */
void Toolbox::setupUiMasterWidget(){
    widget = new QWidget(tabEdit);
    widget->setObjectName(QStringLiteral("widget"));
    widget->setGeometry(QRect(0, 0, tabParent->width(), tabParent->height()));

    musicWidget = new QWidget(tabMusic);
    musicWidget->setObjectName(QStringLiteral("musicWidget"));
    musicWidget->setGeometry(QRect(0,0,tabParent->width(), tabParent->height()));
}

/**
 * Used to create and setup all the label widgets in the toolbox
 * @param A pointer to the "master widget" setup for the editing tab
 */
void Toolbox::setupUiLabels(QWidget *widget)
{
    lblAddFramesStart = new QLabel(widget);
    lblAddFramesStart->setObjectName(QStringLiteral("lblAddFramesStart"));
    toolBoxFont = lblAddFramesStart->font();
    toolBoxFont.setPointSize(8);
    lblAddFramesStart->setFont(toolBoxFont);
    lblAddFramesStart->show();

    lblAddFramesStartSpacer = new QLabel(widget);
    lblAddFramesStartSpacer->setObjectName(QStringLiteral("lblAddFramesStartSpacer"));
    lblAddFramesStartSpacer->show();

    lblAddFramesEnd = new QLabel(widget);
    lblAddFramesEnd->setObjectName(QStringLiteral("lblAddFramesEnd"));
    toolBoxFont = lblAddFramesEnd->font();
    toolBoxFont.setPointSize(8);
    lblAddFramesEnd->setFont(toolBoxFont);
    lblAddFramesEnd->show();

    lblAddFramesEndSpacer = new QLabel(widget);
    lblAddFramesEndSpacer->setObjectName(QStringLiteral("lblAddFramesEndSpacer"));
    lblAddFramesEndSpacer->show();

    lblRemoveFramesFirst = new QLabel(widget);
    lblRemoveFramesFirst->setObjectName(QStringLiteral("lblRemoveFramesFirst"));
    toolBoxFont = lblRemoveFramesFirst->font();
    toolBoxFont.setPointSize(8);
    lblRemoveFramesFirst->setFont(toolBoxFont);
    lblRemoveFramesFirst->show();

    lblRemoveFramesFirstSpacer = new QLabel(widget);
    lblRemoveFramesFirstSpacer->setObjectName(QStringLiteral("lblRemoveFramesFirstSpacer"));
    lblRemoveFramesFirstSpacer->show();

    lblRemoveFramesLast = new QLabel(widget);
    lblRemoveFramesLast->setObjectName(QStringLiteral("lblRemoveFramesLast"));
    toolBoxFont = lblRemoveFramesLast->font();
    toolBoxFont.setPointSize(8);
    lblRemoveFramesLast->setFont(toolBoxFont);
    lblRemoveFramesLast->show();

    lblRemoveFramesLastSpacer = new QLabel(widget);
    lblRemoveFramesLastSpacer->setObjectName(QStringLiteral("lblRemoveFramesLastSpacer"));
    lblRemoveFramesLastSpacer->show();

    lblCopyFramesFrame = new QLabel(widget);
    lblCopyFramesFrame->setObjectName(QStringLiteral("lblCopyFramesFrame"));
    toolBoxFont = lblCopyFramesFrame->font();
    toolBoxFont.setPointSize(8);
    lblCopyFramesFrame->setFont(toolBoxFont);
    lblCopyFramesFrame->show();

    lblCopyFramesFrameSpacer = new QLabel(widget);
    lblCopyFramesFrameSpacer->setObjectName(QStringLiteral("lblCopyFramesFrameSpacer"));
    lblCopyFramesFrameSpacer->show();

    lblCopyFramesStart = new QLabel(widget);
    lblCopyFramesStart->setObjectName(QStringLiteral("lblCopyFramesStart"));
    toolBoxFont = lblCopyFramesStart->font();
    toolBoxFont.setPointSize(8);
    lblCopyFramesStart->setFont(toolBoxFont);
    lblCopyFramesStart->show();

    lblCopyFramesStartSpacer = new QLabel(widget);
    lblCopyFramesStartSpacer->setObjectName(QStringLiteral("lblCopyFramesStartSpacer"));
    lblCopyFramesStartSpacer->show();

    lblCopyFramesEnd = new QLabel(widget);
    lblCopyFramesEnd->setObjectName(QStringLiteral("lblCopyFramesEnd"));
    toolBoxFont = lblCopyFramesEnd->font();
    toolBoxFont.setPointSize(8);
    lblCopyFramesEnd->setFont(toolBoxFont);
    lblCopyFramesEnd->show();

    lblCopyFramesEndSpacer = new QLabel(widget);
    lblCopyFramesEndSpacer->setObjectName(QStringLiteral("lblCopyFramesEndSpacer"));
    lblCopyFramesEndSpacer->show();

    lblTimingCurrentTime = new QLabel(widget);
    lblTimingCurrentTime->setObjectName(QStringLiteral("lblTimingCurrentTime"));
    toolBoxFont = lblTimingCurrentTime->font();
    toolBoxFont.setPointSize(8);
    lblTimingCurrentTime->setFont(toolBoxFont);
    lblTimingCurrentTime->show();

    lblTimingCurrentTimeSpacer1 = new QLabel(widget);
    lblTimingCurrentTimeSpacer1->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer1"));
    lblTimingCurrentTimeSpacer1->show();

    lblTimingCurrentTimeSpacer2 = new QLabel(widget);
    lblTimingCurrentTimeSpacer2->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer2"));
    lblTimingCurrentTimeSpacer2->show();

    lblTimingCurrentTimeSpacer3 = new QLabel(widget);
    lblTimingCurrentTimeSpacer3->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer3"));
    lblTimingCurrentTimeSpacer3->show();

    lblTimingCurrentTimeSpacer4 = new QLabel(widget);
    lblTimingCurrentTimeSpacer4->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer4"));
    lblTimingCurrentTimeSpacer4->show();

    lblTimingTimeInterval = new QLabel(widget);
    lblTimingTimeInterval->setObjectName(QStringLiteral("lblTimingTimeInterval"));
    toolBoxFont = lblTimingTimeInterval->font();
    toolBoxFont.setPointSize(8);
    lblTimingTimeInterval->setFont(toolBoxFont);
    lblTimingTimeInterval->show();

    lblTimingTimeIntervalSpacer1 = new QLabel(widget);
    lblTimingTimeIntervalSpacer1->setObjectName(QStringLiteral("lblTimingTimeIntervalSpacer1"));
    lblTimingTimeIntervalSpacer1->show();

    lblTimingTimeIntervalSpacer2 = new QLabel(widget);
    lblTimingTimeIntervalSpacer2->setObjectName(QStringLiteral("lblTimingTimeIntervalSpacer2"));
    lblTimingTimeIntervalSpacer2->show();

    lblTimingTimeIntervalSpacer3 = new QLabel(widget);
    lblTimingTimeIntervalSpacer3->setObjectName(QStringLiteral("lblTimingTimeIntervalSpacer3"));
    lblTimingTimeIntervalSpacer3->show();

    lblTimingTimeIntervalSpacer4 = new QLabel(widget);
    lblTimingTimeIntervalSpacer4->setObjectName(QStringLiteral("lblTimingTimeIntervalSpacer4"));
    lblTimingTimeIntervalSpacer4->show();
}

void  Toolbox::setupUiLabelsMusic(QWidget *musWidget)
{
    lblMusicFileName = new QLabel(musWidget);
    lblMusicFileName->setObjectName(QStringLiteral("lblMusicFileName"));
    toolBoxFont = lblMusicFileName->font();
    toolBoxFont.setPointSize(8);
    lblMusicFileName->setFont(toolBoxFont);
    lblMusicFileName->show();
}

/**
 * Used to create and setup the various widgets used in the toolbox including Add Frames Widgets, Remove Frames Widgets,
 * Copy Frames Widgets, and Timing Widgets.
 * @param A pointer to the "master widget" setup for the editing tab
 */
void Toolbox::setupUiWidgets(QWidget *widget)
{
    /**
     * Set up Add Frames Widgets
     */
    addFramesStart = new QSpinBox(widget);
    addFramesStart->setObjectName(QStringLiteral("addFramesStart"));
    addFramesStart->connect(addFramesStart, SIGNAL(valueChanged(int)), this, SLOT(on_addFramesStart_valueChanged(int)));
    toolBoxFont = addFramesStart->font();
    toolBoxFont.setPointSize(8);
    addFramesStart->setFont(toolBoxFont);
    //addFramesStart->setRange(0, 0);

    addFramesEnd = new QSpinBox(widget);
    addFramesEnd->setObjectName(QStringLiteral("addFramesEnd"));
    addFramesEnd->connect(addFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_addFramesEnd_valueChanged(int)));
    toolBoxFont = addFramesEnd->font();
    toolBoxFont.setPointSize(8);
    addFramesEnd->setFont(toolBoxFont);
    //addFramesEnd->setRange(0, 999999);

    addFramesButton = new QPushButton(widget);
    addFramesButton->setObjectName(QStringLiteral("addFramesButton"));
    addFramesButton->connect(addFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_addFramesButton_clicked()));
    toolBoxFont = addFramesButton->font();
    toolBoxFont.setPointSize(8);
    addFramesButton->setFont(toolBoxFont);

    /**
     * Set up Remove Frames Widgets
     */
    removeFramesStart = new QSpinBox(widget);
    removeFramesStart->setObjectName(QStringLiteral("removeFramesStart"));
    removeFramesStart->connect(removeFramesStart, SIGNAL(valueChanged(int)), this, SLOT(on_removeFramesStart_valueChanged(int)));
    toolBoxFont = removeFramesStart->font();
    toolBoxFont.setPointSize(8);
    removeFramesStart->setFont(toolBoxFont);
    //removeFramesStart->setRange(0, 0);

    removeFramesEnd = new QSpinBox(widget);
    removeFramesEnd->setObjectName(QStringLiteral("removeFramesEnd"));
    removeFramesEnd->connect(removeFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_removeFramesEnd_valueChanged(int)));
    toolBoxFont = removeFramesEnd->font();
    toolBoxFont.setPointSize(8);
    removeFramesEnd->setFont(toolBoxFont);
    //removeFramesEnd->setRange(0, 0);

    removeFramesButton = new QPushButton(widget);
    removeFramesButton->setObjectName(QStringLiteral("removeFramesButton"));
    removeFramesButton->connect(removeFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_removeFramesButton_clicked()));
    toolBoxFont = removeFramesButton->font();
    toolBoxFont.setPointSize(8);
    removeFramesButton->setFont(toolBoxFont);

    /**
     * Set up Copy Frames Widgets
     */
    copyFramesIndex = new QSpinBox(widget);
    copyFramesIndex->setObjectName(QStringLiteral("copyFramesIndex"));
    copyFramesIndex->connect(copyFramesIndex, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesIndex_valueChanged(int)));
    toolBoxFont = copyFramesIndex->font();
    toolBoxFont.setPointSize(8);
    copyFramesIndex->setFont(toolBoxFont);
    //copyFramesIndex->setRange(0, 0);

    copyFramesStart = new QSpinBox(widget);
    copyFramesStart->setObjectName(QStringLiteral("copyFramesStart"));
    copyFramesStart->connect(copyFramesStart, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesStart_valueChanged(int)));
    toolBoxFont = copyFramesStart->font();
    toolBoxFont.setPointSize(8);
    copyFramesStart->setFont(toolBoxFont);
    //copyFramesStart->setRange(0, 0);

    copyFramesEnd = new QSpinBox(widget);
    copyFramesEnd->setObjectName(QStringLiteral("copyFramesEnd"));
    copyFramesEnd->connect(copyFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesEnd_valueChanged(int)));
    toolBoxFont = copyFramesEnd->font();
    toolBoxFont.setPointSize(8);
    copyFramesEnd->setFont(toolBoxFont);
    //copyFramesEnd->setRange(0, 0);

    copyFramesButton = new QPushButton(widget);
    copyFramesButton->setObjectName(QStringLiteral("copyFramesButton"));
    copyFramesButton->connect(copyFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_copyFramesButton_clicked()));
    toolBoxFont = copyFramesButton->font();
    toolBoxFont.setPointSize(8);
    copyFramesButton->setFont(toolBoxFont);

    /**
     * Set up Timing Widgets
     */
    QTime defaultTime;
    defaultTime.setHMS(0,0,0,100);

    /*currentTime = new QTimeEdit(widget);
    currentTime->setObjectName(QStringLiteral("currentTime"));
    currentTime->connect(currentTime, SIGNAL(timeChanged(QTime)), this, SLOT(on_currentTime_timeChanged(QTime)));
    toolBoxFont = currentTime->font();
    toolBoxFont.setPointSize(8);
    currentTime->setFont(toolBoxFont);
    currentTime->setDisplayFormat("mm:ss.zzz");*/
    //currentTime->setTime(defaultTime);

    timeInterval = new QTimeEdit(widget);
    timeInterval->setObjectName(QStringLiteral("timeInterval"));
    timeInterval->setTimeSpec(Qt::LocalTime);
    timeInterval->connect(timeInterval, SIGNAL(timeChanged(QTime)), this, SLOT(on_timeInterval_timeChanged(QTime)));
    toolBoxFont = timeInterval->font();
    toolBoxFont.setPointSize(8);
    timeInterval->setFont(toolBoxFont);
    timeInterval->setDisplayFormat("mm:ss.zzz");
    timeInterval->setTime(defaultTime);
    animPtr->setTimeInterval(100);
}

void Toolbox::setupUiWidgetsMusic(QWidget *musWidget)
{
    txtMusicFileName = new QLineEdit(musWidget);
    txtMusicFileName->setObjectName(QStringLiteral("txtMusicFileName"));
    toolBoxFont = txtMusicFileName->font();
    toolBoxFont.setPointSize(8);
    txtMusicFileName->setFont(toolBoxFont);
    txtMusicFileName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    btnMusicFileName = new QPushButton(musWidget);
    btnMusicFileName->setObjectName(QStringLiteral("btnMusicFileName"));
    btnMusicFileName->connect(btnMusicFileName, SIGNAL(clicked(bool)), this, SLOT(on_btnMusicFileName_clicked()));
    toolBoxFont = btnMusicFileName->font();
    toolBoxFont.setPointSize(8);
    btnMusicFileName->setFont(toolBoxFont);
}

/**
 * Used to layout all the created widgets neatly
 * @param A pointer to the "master widget" setup for the editing tab
 */
void Toolbox::setupUiLayouts(QWidget *widget)
{
    /**
     * Set up Master Layout
     */
    loMasterLayout = new QVBoxLayout(widget);
    loMasterLayout->setSpacing(6);
    loMasterLayout->setContentsMargins(widget->width()*0.05, widget->height()*0.05, widget->width()*0.05, widget->height()*0.05);
    loMasterLayout->setObjectName(QStringLiteral("loMasterLayout"));

    /**
     * Set up Add Frames Layout
     */
    loAddFrames = new QHBoxLayout();
    loAddFrames->setSpacing(6);
    loAddFrames->setObjectName(QStringLiteral("loAddFrames"));
    loAddFramesStart = new QVBoxLayout();
    loAddFramesStart->setSpacing(6);
    loAddFramesStart->setObjectName(QStringLiteral("loAddFramesStart"));
    loAddFramesStart->addWidget(lblAddFramesStart);
    loAddFramesStart->addWidget(addFramesStart);
    loAddFramesStart->addWidget(lblAddFramesStartSpacer);
    loAddFrames->addLayout(loAddFramesStart);
    loAddFramesEnd = new QVBoxLayout();
    loAddFramesEnd->setSpacing(6);
    loAddFramesEnd->setObjectName(QStringLiteral("loAddFramesEnd"));
    loAddFramesEnd->addWidget(lblAddFramesEnd);
    loAddFramesEnd->addWidget(addFramesEnd);
    loAddFramesEnd->addWidget(lblAddFramesEndSpacer);
    loAddFrames->addLayout(loAddFramesEnd);
    loAddFrames->addWidget(addFramesButton);
    loMasterLayout->addLayout(loAddFrames);

    /**
     * Set up Remove Frames Layout
     */
    loRemoveFrames = new QHBoxLayout();
    loRemoveFrames->setSpacing(6);
    loRemoveFrames->setObjectName(QStringLiteral("loRemoveFrames"));
    loRemoveFramesFirst = new QVBoxLayout();
    loRemoveFramesFirst->setSpacing(6);
    loRemoveFramesFirst->setObjectName(QStringLiteral("loRemoveFramesFirst"));
    loRemoveFramesFirst->addWidget(lblRemoveFramesFirst);
    loRemoveFramesFirst->addWidget(removeFramesStart);
    loRemoveFramesFirst->addWidget(lblRemoveFramesFirstSpacer);
    loRemoveFrames->addLayout(loRemoveFramesFirst);
    loRemoveFramesLast = new QVBoxLayout();
    loRemoveFramesLast->setSpacing(6);
    loRemoveFramesLast->setObjectName(QStringLiteral("loRemoveFramesLast"));
    loRemoveFramesLast->addWidget(lblRemoveFramesLast);
    loRemoveFramesLast->addWidget(removeFramesEnd);
    loRemoveFramesLast->addWidget(lblRemoveFramesLastSpacer);
    loRemoveFrames->addLayout(loRemoveFramesLast);
    loRemoveFrames->addWidget(removeFramesButton);
    loMasterLayout->addLayout(loRemoveFrames);

    /**
     * Set up Copy Frames Layout
     */
    loCopyFrames = new QHBoxLayout();
    loCopyFrames->setSpacing(6);
    loCopyFrames->setObjectName(QStringLiteral("loCopyFrames"));
    loCopyFramesFrame = new QVBoxLayout();
    loCopyFramesFrame->setSpacing(6);
    loCopyFramesFrame->setObjectName(QStringLiteral("loCopyFramesFrame"));
    loCopyFramesFrame->addWidget(lblCopyFramesFrame);
    loCopyFramesFrame->addWidget(copyFramesIndex);
    loCopyFramesFrame->addWidget(lblCopyFramesFrameSpacer);
    loCopyFrames->addLayout(loCopyFramesFrame);
    loCopyFramesStart = new QVBoxLayout();
    loCopyFramesStart->setSpacing(6);
    loCopyFramesStart->setObjectName(QStringLiteral("loCopyFramesStart"));
    loCopyFramesStart->addWidget(lblCopyFramesStart);
    loCopyFramesStart->addWidget(copyFramesStart);
    loCopyFramesStart->addWidget(lblCopyFramesStartSpacer);
    loCopyFrames->addLayout(loCopyFramesStart);
    loCopyFramesEnd = new QVBoxLayout();
    loCopyFramesEnd->setSpacing(6);
    loCopyFramesEnd->setObjectName(QStringLiteral("loCopyFramesEnd"));
    loCopyFramesEnd->addWidget(lblCopyFramesEnd);
    loCopyFramesEnd->addWidget(copyFramesEnd);
    loCopyFramesEnd->addWidget(lblCopyFramesEndSpacer);
    loCopyFrames->addLayout(loCopyFramesEnd);
    loCopyFrames->addWidget(copyFramesButton);
    loMasterLayout->addLayout(loCopyFrames);

    /**
     * Set up Timing Layout
     */
    loTiming = new QHBoxLayout();
    loTiming->setSpacing(6);
    loTiming->setObjectName(QStringLiteral("loTiming"));
    /*loTimingCurrentTime = new QVBoxLayout();
    loTimingCurrentTime->setSpacing(6);
    loTimingCurrentTime->setObjectName(QStringLiteral("loTimingCurrentTime"));
    loTimingCurrentTime->addWidget(lblTimingCurrentTime);
    loTimingCurrentTime->addWidget(currentTime);
    loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer1);
    loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer2);
    loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer3);
    loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer4);
    loTiming->addLayout(loTimingCurrentTime);*/
    loTimingTimeInterval = new QVBoxLayout();
    loTimingTimeInterval->setSpacing(6);
    loTimingTimeInterval->setObjectName(QStringLiteral("loTimingTimeInterval"));
    loTimingTimeInterval->addWidget(lblTimingTimeInterval);
    loTimingTimeInterval->addWidget(timeInterval);
    loTimingTimeInterval->addWidget(lblTimingTimeIntervalSpacer1);
    loTimingTimeInterval->addWidget(lblTimingTimeIntervalSpacer2);
    loTimingTimeInterval->addWidget(lblTimingTimeIntervalSpacer3);
    loTimingTimeInterval->addWidget(lblTimingTimeIntervalSpacer4);
    loTiming->addLayout(loTimingTimeInterval);
    loMasterLayout->addLayout(loTiming);
}

void Toolbox::setupUiLayoutsMusic(QWidget *musWidget)
{
    /**
     * Set up Music Tab Layout
     */
    loMusicMasterLayout = new QVBoxLayout(musWidget);
    loMusicMasterLayout->setSpacing(6);
    loMusicMasterLayout->setContentsMargins(musWidget->width()*0.05, musWidget->height()*0.05, musWidget->width()*0.05, musWidget->height()*0.05);
    loMusicMasterLayout->setObjectName(QStringLiteral("loMusicMasterLayout"));

    loMusicFileName = new QHBoxLayout();
    loMusicFileName->setSpacing(6);
    loMusicFileName->setObjectName(QStringLiteral("loMusicFileName"));

    loMusicFileNameText = new QVBoxLayout();
    loMusicFileNameText->setSpacing(6);
    loMusicFileNameText->setObjectName(QStringLiteral("loMusicFileNameText"));
    loMusicFileNameText->addWidget(lblMusicFileName);
    loMusicFileNameText->addWidget(txtMusicFileName);
    loMusicFileNameText->addSpacing(musWidget->height() * 0.004);
    loMusicFileName->addLayout(loMusicFileNameText);

    loMusicFileNameButton = new QVBoxLayout();
    loMusicFileNameButton->setSpacing(6);
    loMusicFileNameButton->setObjectName(QStringLiteral("loMusicFileNameButton"));
    loMusicFileNameButton->addSpacing(musWidget->height() * 0.05);
    loMusicFileNameButton->addWidget(btnMusicFileName);
    loMusicFileName->addLayout(loMusicFileNameButton);

    loMusicMasterLayout->addLayout(loMusicFileName);
}

/**
 * Function to retranslate the user interface
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::retranslateUi(QWidget *Toolbox)
{
    Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", 0));
    tabParent->setTabText(tabParent->indexOf(tabColor), QApplication::translate("Toolbox", "Color", 0));
    tabParent->setTabText(tabParent->indexOf(tabEdit), QApplication::translate("Toolbox", "Editing", 0));
    tabParent->setTabText(tabParent->indexOf(tabMusic), QApplication::translate("Toolbox", "Music", 0));

    /**
     * Retranslate Add Frames Layout
     */
    lblAddFramesStart->setText(QApplication::translate("Toolbox", "Insertion Starting Index", 0));//
    lblAddFramesStartSpacer->setText(QString());
    lblAddFramesEnd->setText(QApplication::translate("Toolbox", "Number of Frames to Insert", 0));//
    lblAddFramesEndSpacer->setText(QString());
    addFramesButton->setText(QApplication::translate("Toolbox", "Add Frames", 0));

    /**
     * Retranslate Remove Frames Layout
     */
    lblRemoveFramesFirst->setText(QApplication::translate("Toolbox", "Deletion Starting Index", 0));//
    lblRemoveFramesFirstSpacer->setText(QString());
    lblRemoveFramesLast->setText(QApplication::translate("Toolbox", "Number of Frames to Delete", 0));//
    lblRemoveFramesLastSpacer->setText(QString());
    removeFramesButton->setText(QApplication::translate("Toolbox", "Remove Frames", 0));

    /**
     * Retranslate Copy Frames Layout
     */
    lblCopyFramesFrame->setText(QApplication::translate("Toolbox", "Copy Insertion Index", 0));//
    lblCopyFramesFrameSpacer->setText(QString());
    lblCopyFramesStart->setText(QApplication::translate("Toolbox", "Copy Starting Index", 0));//
    lblCopyFramesStartSpacer->setText(QString());
    lblCopyFramesEnd->setText(QApplication::translate("Toolbox", "Copy Ending Index", 0));//
    lblCopyFramesEndSpacer->setText(QString());
    copyFramesButton->setText(QApplication::translate("Toolbox", "Copy Frames", 0));

    /**
     * Retranslate Timing Layout
     */
    /*lblTimingCurrentTime->setText(QApplication::translate("Toolbox", "Current Time", 0));//
    currentTime->setDisplayFormat(QApplication::translate("Toolbox", "mm:ss.zzz", 0));
    lblTimingCurrentTimeSpacer4->setText(QString());
    lblTimingCurrentTimeSpacer3->setText(QString());
    lblTimingCurrentTimeSpacer2->setText(QString());
    lblTimingCurrentTimeSpacer1->setText(QString());*/
    lblTimingTimeInterval->setText(QApplication::translate("Toolbox", "Time interval", 0));//
    timeInterval->setDisplayFormat(QApplication::translate("Toolbox", "mm:ss.zzz", 0));
    lblTimingTimeIntervalSpacer1->setText(QString());
    lblTimingTimeIntervalSpacer2->setText(QString());
    lblTimingTimeIntervalSpacer3->setText(QString());
    lblTimingTimeIntervalSpacer4->setText(QString());

    /**
     * Retranslate Music Layout
     */
    lblMusicFileName->setText(QApplication::translate("Toolbox", "Music File Name", 0));
    txtMusicFileName->setText(QApplication::translate("Toolbox", "NoAudioFile", 0));
    btnMusicFileName->setText(QApplication::translate("Toolbox", "Commit Name", 0));

} // retranslateUi

/**
 * Used to create and setup the color options under the color tab using the QColorDialogue
 */
void Toolbox::setupUiColorDialogue(){
    tabParent->setCurrentIndex(0);

    colorDialog = new QColorDialog(this->tabColor);
    colorDialog->setWindowFlags(Qt::SubWindow);
    colorDialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
    colorDialog->move(0,0);
    colorDialog->show();
    colorDialog->setGeometry(QRect(0,0,tabColor->width(),tabColor->height()));
    colorDialog->connect(colorDialog, SIGNAL(currentColorChanged(QColor)), this, SLOT(on_colorDialog_currentColorChanged(QColor)));
    toolBoxFont = colorDialog->font();
    toolBoxFont.setPointSize(8);
    colorDialog->setFont(toolBoxFont);

    /**
     * Set Geometry of the tab widget to match the color dialogue box with a bit of a buffer each direction to make sure
     * it is big enough
     */
    tabParent->setGeometry(0,0,colorDialog->width(), colorDialog->height() +  colorDialog->height()*0.1);
}

/**
 * Signal for when the value for the end frame box associated with add frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_addFramesStart_valueChanged(int arg1)
{
    addFramesInsertionIndex = arg1;
    qDebug("HERE! on_addFramesStart_valueChanged %d", addFramesInsertionIndex);
}

/**
 * Signal for when the value for the start frame box associated with add frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_addFramesEnd_valueChanged(int arg1)
{
    addFramesNumberOfFrames = arg1;
    qDebug("HERE! on_addFramesEnd_valueChanged %d", addFramesNumberOfFrames);
}

/**
 * Signal for when the button associated with add frames is clicked
 */
void Toolbox::on_addFramesButton_clicked()
{
    for(int i = 0; i < addFramesNumberOfFrames; i++){
        animPtr->addFrame(animPtr->getWidth(), animPtr->getHeight(), addFramesInsertionIndex);
    }
    /* qDebug("HERE! on_copyFramesButton_clicked");
     addFramesStart->setRange(0, animPtr->getNumFrames() - 1);
     removeFramesStart->setRange(0, animPtr->getNumFrames() - 1);
     removeFramesEnd->setRange(0, animPtr->getNumFrames() - removeFramesDeletionIndex - 1);
     copyFramesIndex->setRange(0, animPtr->getNumFrames() - 1);
     copyFramesEnd->setRange(0, animPtr->getNumFrames() - 1);
     copyFramesStart->setRange(0, animPtr->getNumFrames() - 1);*/

    emit updateUI();
}

/**
 * Signal for when the value for the start frame box associated with remove frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_removeFramesStart_valueChanged(int arg1)
{
    removeFramesDeletionIndex = arg1;
    qDebug("HERE! on_removeFramesStart_valueChanged %d", removeFramesDeletionIndex);
    //removeFramesEnd->setRange(0, animPtr->getNumFrames() - removeFramesDeletionIndex - 1);
}

/**
 * Signal for when the value for the end frame box associated with remove frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_removeFramesEnd_valueChanged(int arg1)
{
    removeFramesNumberOfFrames = arg1;
    qDebug("HERE! on_removeFramesEnd_valueChanged %d", removeFramesNumberOfFrames);
}

/**
 * Signal for when the button associated with remove frames is clicked
 */
void Toolbox::on_removeFramesButton_clicked()
{
    std::list<Frame> frames = animPtr->getFrames();

    if(removeFramesDeletionIndex+removeFramesNumberOfFrames <= animPtr->getNumFrames() && removeFramesNumberOfFrames != 0) {
        std::list<Frame>::iterator startIt = frames.begin();
        std::list<Frame>::iterator endIt = frames.begin();

        std::advance(startIt,removeFramesDeletionIndex);
        std::advance(endIt,removeFramesDeletionIndex+removeFramesNumberOfFrames);

        frames.erase(startIt,endIt);
        animPtr->setFrames(frames);
    }
    /* qDebug("HERE! on_copyFramesButton_clicked");
     addFramesStart->setRange(0, animPtr->getNumFrames() - 1);
     removeFramesStart->setRange(0, animPtr->getNumFrames() - 1);
     removeFramesEnd->setRange(0, animPtr->getNumFrames() - removeFramesDeletionIndex - 1);
     copyFramesIndex->setRange(0, animPtr->getNumFrames() - 1);
     copyFramesEnd->setRange(0, animPtr->getNumFrames() - 1);
     copyFramesStart->setRange(0, animPtr->getNumFrames() - 1);*/

        emit updateUI();
}

/**
 * Signal for when the value for the index frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesIndex_valueChanged(int arg1)
{
    copyFramesInsertionIndex = arg1;
    qDebug("HERE! on_copyFramesIndex_valueChanged %d", copyFramesInsertionIndex);
}

/**
 * Signal for when the value for the start frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesStart_valueChanged(int arg1)
{
    copyFramesStartIndex = arg1;
    //copyFramesEnd->setRange(copyFramesStartIndex, animPtr->getNumFrames() - 1);
    qDebug("HERE! on_copyFramesStart_valueChanged %d", copyFramesStartIndex);
}

/**
 * Signal for when the value for the end frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesEnd_valueChanged(int arg1)
{
    copyFramesEndIndex = arg1;
    //copyFramesStart->setRange(0, copyFramesEnd->maximum());
    qDebug("HERE! on_copyFramesEnd_valueChanged %d", copyFramesEndIndex);
}

/**
 * Signal for when the button associated with copy frames is clicked
 */
void Toolbox::on_copyFramesButton_clicked()
{
    std::list<Frame> frames = animPtr->getFrames();
    std::list<Frame> tempFrames = animPtr->getFrames();

    std::list<Frame>::iterator insertIt = frames.begin();
    std::list<Frame>::iterator startCopyIt = tempFrames.begin();
    std::list<Frame>::iterator endCopyIt = tempFrames.begin();

    std::advance(insertIt,copyFramesInsertionIndex);
    std::advance(startCopyIt,copyFramesStartIndex);
    std::advance(endCopyIt,copyFramesEndIndex);

    frames.splice(insertIt,tempFrames,startCopyIt,endCopyIt);

    animPtr->setFrames(frames);

   /* qDebug("HERE! on_copyFramesButton_clicked");
    addFramesStart->setRange(0, animPtr->getNumFrames() - 1);
    removeFramesStart->setRange(0, animPtr->getNumFrames() - 1);
    removeFramesEnd->setRange(0, animPtr->getNumFrames() - removeFramesDeletionIndex - 1);
    copyFramesIndex->setRange(0, animPtr->getNumFrames() - 1);
    copyFramesEnd->setRange(0, animPtr->getNumFrames() - 1);
    copyFramesStart->setRange(0, animPtr->getNumFrames() - 1);*/

    emit updateUI();
}

/**
 * Signal for when the value for the current time box associated with time intervals is changed
 * @param A QTime value of what the time has been changed to
 */
void Toolbox::on_currentTime_timeChanged(QTime timeVal)
{
    qDebug("HERE! on_currentTime_timeChanged %d:%d:%d", timeVal.minute(), timeVal.second(), timeVal.msec());
    int ms = (timeVal.minute() * 60000) + (timeVal.second() * 1000) + (timeVal.msec());
    animPtr->getCurrentFrame()->setStartTime(ms);
    qDebug("HERE! on_currentTime_timeChanged in ms: %d", ms);
}

/**
 * Signal for when the value for the interval time box associated with time intervals is changed
 * @param A QTime value of what the time has been changed to
 */
void Toolbox::on_timeInterval_timeChanged(QTime timeVal)
{
    qDebug("HERE! on_timeInterval_timeChanged %d:%d:%d", timeVal.minute(), timeVal.second(), timeVal.msec());
    int ms = (timeVal.minute() * 60000) + (timeVal.second() * 1000) + (timeVal.msec());
    qDebug("HERE! on_timeInterval_timeChanged in ms: %d", ms);
    animPtr->setTimeInterval(ms);
}

/**
 * Signal for when the the current selected color has been changed
 * @param A QColor value of what the color has been changed to
 */
void Toolbox::on_colorDialog_currentColorChanged(QColor colorVal)
{
    qDebug("HERE! on_colorDialog_currentColorChanged %d:%d:%d", colorVal.red(), colorVal.green(), colorVal.blue());
    animPtr->setLastColor(colorVal.red(), colorVal.green(), colorVal.blue());
}

/**
 * Signal for when the button associated with setting the music file name is clicked
 */
void Toolbox::on_btnMusicFileName_clicked()
{
    qDebug("HERE! on_btnMusicFileName_clicked %s", txtMusicFileName->text().toLatin1().constData());
    animPtr->setFilename(txtMusicFileName->text().toStdString());
}
