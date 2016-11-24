/**
 * CS 383
 * Group #4
 * Created: 11/17/2016
 *
 * This file contains the implimentations of the Toolbox class used
 * to hold the color picker widget and other tools.
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
#include "toolbox.h"

/**
 * Set up the User interface elements according to the
 * defined layout in the Qt Creator editor
 */

Toolbox::Toolbox(QWidget *parent = 0){
    setupUi(this);
}

Toolbox::~Toolbox(){

}

void Toolbox::setupUi(QWidget *Toolbox)
{
    if (Toolbox->objectName().isEmpty()){
        Toolbox->setObjectName(QStringLiteral("Toolbox"));
    }

    Toolbox->resize(530, 635);

    setupUiTabs(Toolbox);

    setupUiMasterWidget();

    setupUiLabels(widget);

    setupUiWidgets(widget);

    setupUiLayouts(widget);

    setupUiColorDialogue();

    retranslateUi(Toolbox);

    //QMetaObject::connectSlotsByName(Toolbox);
} // setupUi

void Toolbox::setupUiTabs(QWidget *Toolbox){
    tabWidget = new QTabWidget(Toolbox);
    tabWidget->setObjectName(QStringLiteral("tabWidget"));
    tabWidget->setGeometry(QRect(10, 10, 511, 621));
    tabWidget->setAutoFillBackground(false);

    tab = new QWidget();
    tab->setObjectName(QStringLiteral("tab"));
    tabWidget->addTab(tab, QString());

    tab_2 = new QWidget();
    tab_2->setObjectName(QStringLiteral("tab_2"));
    tabWidget->addTab(tab_2, QString());
}

void Toolbox::setupUiMasterWidget(){
    widget = new QWidget(tab_2);
    widget->setObjectName(QStringLiteral("widget"));
    widget->setGeometry(QRect(9, 9, 481, 581));
}

void Toolbox::setupUiLabels(QWidget *widget)
{
    label = new QLabel(widget);
    label->setObjectName(QStringLiteral("label"));

    label_6 = new QLabel(widget);
    label_6->setObjectName(QStringLiteral("label_6"));

    label_2 = new QLabel(widget);
    label_2->setObjectName(QStringLiteral("label_2"));

    label_5 = new QLabel(widget);
    label_5->setObjectName(QStringLiteral("label_5"));

    label_9 = new QLabel(widget);
    label_9->setObjectName(QStringLiteral("label_9"));

    label_10 = new QLabel(widget);
    label_10->setObjectName(QStringLiteral("label_10"));

    label_7 = new QLabel(widget);
    label_7->setObjectName(QStringLiteral("label_7"));

    label_11 = new QLabel(widget);
    label_11->setObjectName(QStringLiteral("label_11"));

    label_4 = new QLabel(widget);
    label_4->setObjectName(QStringLiteral("label_4"));

    label_17 = new QLabel(widget);
    label_17->setObjectName(QStringLiteral("label_17"));

    label_12 = new QLabel(widget);
    label_12->setObjectName(QStringLiteral("label_12"));

    label_3 = new QLabel(widget);
    label_3->setObjectName(QStringLiteral("label_3"));

    label_13 = new QLabel(widget);
    label_13->setObjectName(QStringLiteral("label_13"));

    label_8 = new QLabel(widget);
    label_8->setObjectName(QStringLiteral("label_8"));

    label_14 = new QLabel(widget);
    label_14->setObjectName(QStringLiteral("label_14"));

    label_15 = new QLabel(widget);
    label_15->setObjectName(QStringLiteral("label_15"));

    label_23 = new QLabel(widget);
    label_23->setObjectName(QStringLiteral("label_23"));

    label_21 = new QLabel(widget);
    label_21->setObjectName(QStringLiteral("label_21"));

    label_19 = new QLabel(widget);
    label_19->setObjectName(QStringLiteral("label_19"));

    label_16 = new QLabel(widget);
    label_16->setObjectName(QStringLiteral("label_16"));

    label_24 = new QLabel(widget);
    label_24->setObjectName(QStringLiteral("label_24"));

    label_22 = new QLabel(widget);
    label_22->setObjectName(QStringLiteral("label_22"));

    label_20 = new QLabel(widget);
    label_20->setObjectName(QStringLiteral("label_20"));

    label_18 = new QLabel(widget);
    label_18->setObjectName(QStringLiteral("label_18"));
}

void Toolbox::setupUiWidgets(QWidget *widget)
{
    addFramesStart = new QSpinBox(widget);
    addFramesStart->setObjectName(QStringLiteral("addFramesStart"));

    addFramesEnd = new QSpinBox(widget);
    addFramesEnd->setObjectName(QStringLiteral("addFramesEnd"));

    addFramesButton = new QPushButton(widget);
    addFramesButton->setObjectName(QStringLiteral("addFramesButton"));

    removeFramesStart = new QSpinBox(widget);
    removeFramesStart->setObjectName(QStringLiteral("removeFramesStart"));

    removeFramesEnd = new QSpinBox(widget);
    removeFramesEnd->setObjectName(QStringLiteral("removeFramesEnd"));

    removeFramesButton = new QPushButton(widget);
    removeFramesButton->setObjectName(QStringLiteral("removeFramesButton"));

    copyFramesIndex = new QSpinBox(widget);
    copyFramesIndex->setObjectName(QStringLiteral("copyFramesIndex"));

    copyFramesStart = new QSpinBox(widget);
    copyFramesStart->setObjectName(QStringLiteral("copyFramesStart"));

    copyFramesEnd = new QSpinBox(widget);
    copyFramesEnd->setObjectName(QStringLiteral("copyFramesEnd"));

    copyFramesButton = new QPushButton(widget);
    copyFramesButton->setObjectName(QStringLiteral("copyFramesButton"));

    //widget->connect(Toolbox::copyFramesButton, SIGNAL(clicked(bool)), SLOT(Toolbox::on_copyFramesButton_clicked()));
    copyFramesButton->connect(copyFramesButton, SIGNAL(clicked(bool)), SLOT(Toolbox::on_copyFramesButton_clicked()));

    currentTime = new QTimeEdit(widget);
    currentTime->setObjectName(QStringLiteral("currentTime"));

    timeInterval = new QTimeEdit(widget);
    timeInterval->setObjectName(QStringLiteral("timeInterval"));
    timeInterval->setTimeSpec(Qt::LocalTime);
}

void Toolbox::setupUiLayouts(QWidget *widget)
{
    verticalLayout_10 = new QVBoxLayout(widget);
    verticalLayout_10->setSpacing(6);
    verticalLayout_10->setContentsMargins(11, 11, 11, 11);
    verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
    verticalLayout_10->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    verticalLayout->addWidget(label);
    verticalLayout->addWidget(addFramesStart);
    verticalLayout->addWidget(label_6);
    horizontalLayout->addLayout(verticalLayout);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    verticalLayout_2->addWidget(label_2);
    verticalLayout_2->addWidget(addFramesEnd);
    verticalLayout_2->addWidget(label_5);
    horizontalLayout->addLayout(verticalLayout_2);
    horizontalLayout->addWidget(addFramesButton);
    verticalLayout_10->addLayout(horizontalLayout);
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
    verticalLayout_3->addWidget(label_9);
    verticalLayout_3->addWidget(removeFramesStart);
    verticalLayout_3->addWidget(label_10);
    horizontalLayout_2->addLayout(verticalLayout_3);
    verticalLayout_4 = new QVBoxLayout();
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
    verticalLayout_4->addWidget(label_7);
    verticalLayout_4->addWidget(removeFramesEnd);
    verticalLayout_4->addWidget(label_11);
    horizontalLayout_2->addLayout(verticalLayout_4);
    horizontalLayout_2->addWidget(removeFramesButton);
    verticalLayout_10->addLayout(horizontalLayout_2);
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setSpacing(6);
    verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
    verticalLayout_5->addWidget(label_4);
    verticalLayout_5->addWidget(copyFramesIndex);
    verticalLayout_5->addWidget(label_12);
    horizontalLayout_3->addLayout(verticalLayout_5);
    verticalLayout_6 = new QVBoxLayout();
    verticalLayout_6->setSpacing(6);
    verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
    verticalLayout_6->addWidget(label_3);
    verticalLayout_6->addWidget(copyFramesStart);
    verticalLayout_6->addWidget(label_13);
    horizontalLayout_3->addLayout(verticalLayout_6);
    verticalLayout_7 = new QVBoxLayout();
    verticalLayout_7->setSpacing(6);
    verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
    verticalLayout_7->addWidget(label_8);
    verticalLayout_7->addWidget(copyFramesEnd);
    verticalLayout_7->addWidget(label_14);
    horizontalLayout_3->addLayout(verticalLayout_7);
    horizontalLayout_3->addWidget(copyFramesButton);
    verticalLayout_10->addLayout(horizontalLayout_3);
    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
    verticalLayout_8 = new QVBoxLayout();
    verticalLayout_8->setSpacing(6);
    verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
    verticalLayout_8->addWidget(label_15);
    verticalLayout_8->addWidget(currentTime);
    verticalLayout_8->addWidget(label_23);
    verticalLayout_8->addWidget(label_21);
    verticalLayout_8->addWidget(label_19);
    verticalLayout_8->addWidget(label_17);
    horizontalLayout_4->addLayout(verticalLayout_8);
    verticalLayout_9 = new QVBoxLayout();
    verticalLayout_9->setSpacing(6);
    verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
    verticalLayout_9->addWidget(label_16);
    verticalLayout_9->addWidget(timeInterval);
    verticalLayout_9->addWidget(label_24);
    verticalLayout_9->addWidget(label_22);
    verticalLayout_9->addWidget(label_20);
    verticalLayout_9->addWidget(label_18);
    horizontalLayout_4->addLayout(verticalLayout_9);
    verticalLayout_10->addLayout(horizontalLayout_4);
}

/**
 * Function to retranslate the user interface
 */
void Toolbox::retranslateUi(QWidget *Toolbox)
{
    Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", 0));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Toolbox", "Color", 0));
    label->setText(QApplication::translate("Toolbox", "                     Start", 0));
    label_6->setText(QString());
    label_2->setText(QApplication::translate("Toolbox", "                      End", 0));
    label_5->setText(QString());
    addFramesButton->setText(QApplication::translate("Toolbox", "Add Frames", 0));
    label_9->setText(QApplication::translate("Toolbox", "                      First", 0));
    label_10->setText(QString());
    label_7->setText(QApplication::translate("Toolbox", "                      Last", 0));
    label_11->setText(QString());
    removeFramesButton->setText(QApplication::translate("Toolbox", "Remove Frames", 0));
    label_4->setText(QApplication::translate("Toolbox", "              Frame", 0));
    label_12->setText(QString());
    label_3->setText(QApplication::translate("Toolbox", "               Start", 0));
    label_13->setText(QString());
    label_8->setText(QApplication::translate("Toolbox", "               End", 0));
    label_14->setText(QString());
    copyFramesButton->setText(QApplication::translate("Toolbox", "Copy Frames", 0));
    label_15->setText(QApplication::translate("Toolbox", "                             Current Time", 0));
    currentTime->setDisplayFormat(QApplication::translate("Toolbox", "h:mm.ss", 0));
    label_23->setText(QString());
    label_21->setText(QString());
    label_19->setText(QString());
    label_17->setText(QString());
    label_16->setText(QApplication::translate("Toolbox", "                             Time interval", 0));
    timeInterval->setDisplayFormat(QApplication::translate("Toolbox", "h:mm.ss", 0));
    label_24->setText(QString());
    label_22->setText(QString());
    label_20->setText(QString());
    label_18->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Toolbox", "Editing", 0));
} // retranslateUi

void Toolbox::setupUiColorDialogue(){
    tabWidget->setCurrentIndex(0);

    dialog = new QColorDialog(this->tab);
    dialog->setWindowFlags(Qt::SubWindow);
    dialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
    dialog->move(0,50);
}

/**
 * Signal Function Stubs
 */
void Toolbox::on_addFramesEnd_valueChanged(int arg1)
{

}

void Toolbox::on_addFramesStart_valueChanged(int arg1)
{

}

void Toolbox::on_addFramesButton_clicked()
{

}

void Toolbox::on_removeFramesStart_valueChanged(int arg1)
{

}

void Toolbox::on_removeFramesEnd_valueChanged(int arg1)
{

}

void Toolbox::on_removeFramesButton_clicked()
{

}

void Toolbox::on_copyFramesStart_valueChanged(int arg1)
{

}

void Toolbox::on_copyFramesEnd_valueChanged(int arg1)
{

}

void Toolbox::on_copyFramesIndex_valueChanged(int arg1)
{

}

/*void Toolbox::on_addFramesButton_click()
{
    qDebug("HERE! on_addFramesButton_click");
}*/

void Toolbox::on_copyFramesButton_clicked()
{
    qDebug("HERE! on_copyFramesButton_clicked");
}

void Toolbox::colorChanged()
{

}
