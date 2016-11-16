/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

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

QT_BEGIN_NAMESPACE

class Ui_Toolbox
{
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

    void setupUi(QWidget *Toolbox)
    {
        if (Toolbox->objectName().isEmpty())
            Toolbox->setObjectName(QStringLiteral("Toolbox"));
        Toolbox->resize(530, 635);
        tabWidget = new QTabWidget(Toolbox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 521, 611));
        tabWidget->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        addFramesStart = new QSpinBox(tab_2);
        addFramesStart->setObjectName(QStringLiteral("addFramesStart"));

        horizontalLayout_5->addWidget(addFramesStart);

        addFramesEnd = new QSpinBox(tab_2);
        addFramesEnd->setObjectName(QStringLiteral("addFramesEnd"));

        horizontalLayout_5->addWidget(addFramesEnd);

        addFramesButton = new QPushButton(tab_2);
        addFramesButton->setObjectName(QStringLiteral("addFramesButton"));

        horizontalLayout_5->addWidget(addFramesButton);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        copyFramesStart = new QSpinBox(tab_2);
        copyFramesStart->setObjectName(QStringLiteral("copyFramesStart"));

        horizontalLayout_2->addWidget(copyFramesStart);

        copyFramesEnd = new QSpinBox(tab_2);
        copyFramesEnd->setObjectName(QStringLiteral("copyFramesEnd"));

        horizontalLayout_2->addWidget(copyFramesEnd);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        copyFramesIndex = new QSpinBox(tab_2);
        copyFramesIndex->setObjectName(QStringLiteral("copyFramesIndex"));

        horizontalLayout->addWidget(copyFramesIndex);

        copyFramesButton = new QPushButton(tab_2);
        copyFramesButton->setObjectName(QStringLiteral("copyFramesButton"));

        horizontalLayout->addWidget(copyFramesButton);


        horizontalLayout_3->addLayout(horizontalLayout);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        removeFramesStart = new QSpinBox(tab_2);
        removeFramesStart->setObjectName(QStringLiteral("removeFramesStart"));

        horizontalLayout_4->addWidget(removeFramesStart);

        removeFramesEnd = new QSpinBox(tab_2);
        removeFramesEnd->setObjectName(QStringLiteral("removeFramesEnd"));

        horizontalLayout_4->addWidget(removeFramesEnd);

        removeFramesButton = new QPushButton(tab_2);
        removeFramesButton->setObjectName(QStringLiteral("removeFramesButton"));

        horizontalLayout_4->addWidget(removeFramesButton);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(Toolbox);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Toolbox);
    } // setupUi

    void retranslateUi(QWidget *Toolbox)
    {
        Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Toolbox", "Color", 0));
        addFramesButton->setText(QApplication::translate("Toolbox", "Add Frames", 0));
        copyFramesButton->setText(QApplication::translate("Toolbox", "Copy Frames", 0));
        removeFramesButton->setText(QApplication::translate("Toolbox", "Remove Frames", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Toolbox", "Editing", 0));
    } // retranslateUi

};

namespace Ui {
    class Toolbox: public Ui_Toolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
