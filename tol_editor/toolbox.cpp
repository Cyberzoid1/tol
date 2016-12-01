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
#include <mainwindow.h>
#include <QRect>
#include "toolbox.h"

/**
 * Constructor that sets up the User interface elements according to the
 * defined layout in the Qt Creator editor
 * @param A pointer to the parent widget of the toolbox
 */
Toolbox::Toolbox(QWidget *parent) {
	setupUi(parent);
}

/**
 * Default destructor, empty for future use. 
 */
Toolbox::~Toolbox() {

}

/**
 * Sets up the entire graphical user interface for the toolbox
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::setupUi(QWidget *parent)
{
	if (parent->objectName().isEmpty()) {
		parent->setObjectName(QStringLiteral("Toolbox"));
	}

	setupUiTabs(parent);

	setupUiColorDialogue();

	setupUiMasterWidget();

	setupUiLabels(widget);

	setupUiWidgets(widget);

	setupUiLayouts(widget);

	retranslateUi(parent);

} // setupUi

/**
 * Used to create the tab widget in the toolbox
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::setupUiTabs(QWidget *Toolbox) {
	tabParent = new QTabWidget(Toolbox);
	tabParent->setObjectName(QStringLiteral("tabParent"));
	tabParent->setGeometry(QRect(0, 0, Toolbox->width(), Toolbox->height()));//QRect(10, 10, 511, 621)
	tabParent->setAutoFillBackground(false);
	tabParent->show();

	tabColor = new QWidget();
	tabColor->setObjectName(QStringLiteral("tabColor"));
	tabColor->setGeometry(QRect(0, 0, tabParent->width(), tabParent->height()));
	tabParent->addTab(tabColor, QString());

	tabEdit = new QWidget();
	tabEdit->setObjectName(QStringLiteral("tabEdit"));
	tabEdit->setGeometry(QRect(0, 0, tabParent->width(), tabParent->height()));
	tabParent->addTab(tabEdit, QString());

}

/**
 * Used to create the widget that the editing portion of the toolbox is made in
 */
void Toolbox::setupUiMasterWidget() {
	widget = new QWidget(tabEdit);
	widget->setObjectName(QStringLiteral("widget"));
	widget->setGeometry(QRect(0, 0, tabParent->width(), tabParent->height())); //QRect(9, 9, 481, 581)
}
/**
 * Used to create and setup all the label widgets in the toolbox
 * @param A pointer to the "master widget" setup for the editing tab
 */
void Toolbox::setupUiLabels(QWidget *widget)
{
	lblAddFramesStart = new QLabel(widget);
	lblAddFramesStart->setObjectName(QStringLiteral("lblAddFramesStart"));
	lblAddFramesStart->show();

	lblAddFramesStartSpacer = new QLabel(widget);
	lblAddFramesStartSpacer->setObjectName(QStringLiteral("lblAddFramesStartSpacer"));
	lblAddFramesStartSpacer->show();

	lblAddFramesEnd = new QLabel(widget);
	lblAddFramesEnd->setObjectName(QStringLiteral("lblAddFramesEnd"));
	lblAddFramesEnd->show();

	lblAddFramesEndSpacer = new QLabel(widget);
	lblAddFramesEndSpacer->setObjectName(QStringLiteral("lblAddFramesEndSpacer"));
	lblAddFramesEndSpacer->show();

	lblRemoveFramesFirst = new QLabel(widget);
	lblRemoveFramesFirst->setObjectName(QStringLiteral("lblRemoveFramesFirst"));
	lblRemoveFramesFirst->show();

	lblRemoveFramesFirstSpacer = new QLabel(widget);
	lblRemoveFramesFirstSpacer->setObjectName(QStringLiteral("lblRemoveFramesFirstSpacer"));
	lblRemoveFramesFirstSpacer->show();

	lblRemoveFramesLast = new QLabel(widget);
	lblRemoveFramesLast->setObjectName(QStringLiteral("lblRemoveFramesLast"));
	lblRemoveFramesLast->show();

	lblRemoveFramesLastSpacer = new QLabel(widget);
	lblRemoveFramesLastSpacer->setObjectName(QStringLiteral("lblRemoveFramesLastSpacer"));
	lblRemoveFramesLastSpacer->show();

	lblCopyFramesFrame = new QLabel(widget);
	lblCopyFramesFrame->setObjectName(QStringLiteral("lblCopyFramesFrame"));
	lblCopyFramesFrame->show();

	lblTimingCurrentTimeSpacer1 = new QLabel(widget);
	lblTimingCurrentTimeSpacer1->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer1"));
	lblTimingCurrentTimeSpacer1->show();

	lblCopyFramesFrameSpacer = new QLabel(widget);
	lblCopyFramesFrameSpacer->setObjectName(QStringLiteral("lblCopyFramesFrameSpacer"));
	lblCopyFramesFrameSpacer->show();

	lblCopyFramesStart = new QLabel(widget);
	lblCopyFramesStart->setObjectName(QStringLiteral("lblCopyFramesStart"));
	lblCopyFramesStart->show();

	lblCopyFramesStartSpacer = new QLabel(widget);
	lblCopyFramesStartSpacer->setObjectName(QStringLiteral("lblCopyFramesStartSpacer"));
	lblCopyFramesStartSpacer->show();

	lblCopyFramesEnd = new QLabel(widget);
	lblCopyFramesEnd->setObjectName(QStringLiteral("lblCopyFramesEnd"));
	lblCopyFramesEnd->show();

	lblCopyFramesEndSpacer = new QLabel(widget);
	lblCopyFramesEndSpacer->setObjectName(QStringLiteral("lblCopyFramesEndSpacer"));
	lblCopyFramesEndSpacer->show();

	lblTimingCurrentTime = new QLabel(widget);
	lblTimingCurrentTime->setObjectName(QStringLiteral("lblTimingCurrentTime"));
	lblTimingCurrentTime->show();

	lblTimingCurrentTimeSpacer4 = new QLabel(widget);
	lblTimingCurrentTimeSpacer4->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer4"));
	lblTimingCurrentTimeSpacer4->show();

	lblTimingCurrentTimeSpacer3 = new QLabel(widget);
	lblTimingCurrentTimeSpacer3->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer3"));
	lblTimingCurrentTimeSpacer3->show();

	lblTimingCurrentTimeSpacer2 = new QLabel(widget);
	lblTimingCurrentTimeSpacer2->setObjectName(QStringLiteral("lblTimingCurrentTimeSpacer2"));
	lblTimingCurrentTimeSpacer2->show();

	lblTimingTimeInterval = new QLabel(widget);
	lblTimingTimeInterval->setObjectName(QStringLiteral("lblTimingTimeInterval"));
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

	addFramesEnd = new QSpinBox(widget);
	addFramesEnd->setObjectName(QStringLiteral("addFramesEnd"));
	addFramesEnd->connect(addFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_addFramesEnd_valueChanged(int)));

	addFramesButton = new QPushButton(widget);
	addFramesButton->setObjectName(QStringLiteral("addFramesButton"));
	addFramesButton->connect(addFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_addFramesButton_clicked()));

	/**
	* Set up Remove Frames Widgets
	*/
	removeFramesStart = new QSpinBox(widget);
	removeFramesStart->setObjectName(QStringLiteral("removeFramesStart"));
	removeFramesStart->connect(removeFramesStart, SIGNAL(valueChanged(int)), this, SLOT(on_removeFramesStart_valueChanged(int)));

	removeFramesEnd = new QSpinBox(widget);
	removeFramesEnd->setObjectName(QStringLiteral("removeFramesEnd"));
	removeFramesEnd->connect(removeFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_removeFramesEnd_valueChanged(int)));

	removeFramesButton = new QPushButton(widget);
	removeFramesButton->setObjectName(QStringLiteral("removeFramesButton"));
	removeFramesButton->connect(removeFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_removeFramesButton_clicked()));

	/**
	* Set up Copy Frames Widgets
	*/
	copyFramesIndex = new QSpinBox(widget);
	copyFramesIndex->setObjectName(QStringLiteral("copyFramesIndex"));
	copyFramesIndex->connect(copyFramesIndex, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesIndex_valueChanged(int)));

	copyFramesStart = new QSpinBox(widget);
	copyFramesStart->setObjectName(QStringLiteral("copyFramesStart"));
	copyFramesStart->connect(copyFramesStart, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesStart_valueChanged(int)));

	copyFramesEnd = new QSpinBox(widget);
	copyFramesEnd->setObjectName(QStringLiteral("copyFramesEnd"));
	copyFramesEnd->connect(copyFramesEnd, SIGNAL(valueChanged(int)), this, SLOT(on_copyFramesEnd_valueChanged(int)));

	copyFramesButton = new QPushButton(widget);
	copyFramesButton->setObjectName(QStringLiteral("copyFramesButton"));
	copyFramesButton->connect(copyFramesButton, SIGNAL(clicked(bool)), this, SLOT(on_copyFramesButton_clicked()));

	/**
	* Set up Timing Widgets
	*/
	currentTime = new QTimeEdit(widget);
	currentTime->setObjectName(QStringLiteral("currentTime"));
	currentTime->connect(currentTime, SIGNAL(timeChanged(QTime)), this, SLOT(on_currentTime_timeChanged(QTime)));

	timeInterval = new QTimeEdit(widget);
	timeInterval->setObjectName(QStringLiteral("timeInterval"));
	timeInterval->setTimeSpec(Qt::LocalTime);
	timeInterval->connect(timeInterval, SIGNAL(timeChanged(QTime)), this, SLOT(on_timeInterval_timeChanged(QTime)));
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
	loTimingCurrentTime = new QVBoxLayout();
	loTimingCurrentTime->setSpacing(6);
	loTimingCurrentTime->setObjectName(QStringLiteral("loTimingCurrentTime"));
	loTimingCurrentTime->addWidget(lblTimingCurrentTime);
	loTimingCurrentTime->addWidget(currentTime);
	loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer1);
	loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer2);
	loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer3);
	loTimingCurrentTime->addWidget(lblTimingCurrentTimeSpacer4);
	loTiming->addLayout(loTimingCurrentTime);
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

/**
 * Function to retranslate the user interface
 * @param A pointer to the parent widget of the toolbox
 */
void Toolbox::retranslateUi(QWidget *Toolbox)
{
	Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", 0));
	tabParent->setTabText(tabParent->indexOf(tabColor), QApplication::translate("Toolbox", "Color", 0));
	tabParent->setTabText(tabParent->indexOf(tabEdit), QApplication::translate("Toolbox", "Editing", 0));

	/**
	* Retranslate Add Frames Layout
	*/
	lblAddFramesStart->setText(QApplication::translate("Toolbox", "Start", 0));//
	lblAddFramesStartSpacer->setText(QString());
	lblAddFramesEnd->setText(QApplication::translate("Toolbox", "End", 0));//
	lblAddFramesEndSpacer->setText(QString());
	addFramesButton->setText(QApplication::translate("Toolbox", "Add Frames", 0));

	/**
	* Retranslate Remove Frames Layout
	*/
	lblRemoveFramesFirst->setText(QApplication::translate("Toolbox", "First", 0));//
	lblRemoveFramesFirstSpacer->setText(QString());
	lblRemoveFramesLast->setText(QApplication::translate("Toolbox", "Last", 0));//
	lblRemoveFramesLastSpacer->setText(QString());
	removeFramesButton->setText(QApplication::translate("Toolbox", "Remove Frames", 0));

	/**
	* Retranslate Copy Frames Layout
	*/
	lblCopyFramesFrame->setText(QApplication::translate("Toolbox", "Frame", 0));//
	lblCopyFramesFrameSpacer->setText(QString());
	lblCopyFramesStart->setText(QApplication::translate("Toolbox", "Start", 0));//
	lblCopyFramesStartSpacer->setText(QString());
	lblCopyFramesEnd->setText(QApplication::translate("Toolbox", "End", 0));//
	lblCopyFramesEndSpacer->setText(QString());
	copyFramesButton->setText(QApplication::translate("Toolbox", "Copy Frames", 0));

	/**
	* Retranslate Timing Layout
	*/
	lblTimingCurrentTime->setText(QApplication::translate("Toolbox", "Current Time", 0));//
	currentTime->setDisplayFormat(QApplication::translate("Toolbox", "h:mm.ss", 0));
	lblTimingCurrentTimeSpacer4->setText(QString());
	lblTimingCurrentTimeSpacer3->setText(QString());
	lblTimingCurrentTimeSpacer2->setText(QString());
	lblTimingCurrentTimeSpacer1->setText(QString());
	lblTimingTimeInterval->setText(QApplication::translate("Toolbox", "Time interval", 0));//
	timeInterval->setDisplayFormat(QApplication::translate("Toolbox", "h:mm.ss", 0));
	lblTimingTimeIntervalSpacer1->setText(QString());
	lblTimingTimeIntervalSpacer2->setText(QString());
	lblTimingTimeIntervalSpacer3->setText(QString());
	lblTimingTimeIntervalSpacer4->setText(QString());
} // retranslateUi

/**
 * Used to create and setup the color options under the color tab using the QColorDialogue
 */ 
void Toolbox::setupUiColorDialogue() {
	tabParent->setCurrentIndex(0);

	colorDialog = new QColorDialog(this->tabColor);
	colorDialog->setWindowFlags(Qt::SubWindow);
	colorDialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
	colorDialog->move(0, 0);
	colorDialog->show();
	colorDialog->setGeometry(QRect(0, 0, tabColor->width(), tabColor->height()));
	colorDialog->connect(colorDialog, SIGNAL(currentColorChanged(QColor)), this, SLOT(on_colorDialog_currentColorChanged(QColor)));

	/**
	* Set Geometry of the tab widget to match the color dialogue box with a bit of a buffer each direction to make sure
	* it is big enough
	*/
	tabParent->setGeometry(0, 0, colorDialog->width(), colorDialog->height() + colorDialog->height()*0.1);
}

/**
 * Signal for when the value for the end frame box associated with add frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_addFramesEnd_valueChanged(int arg1)
{
	qDebug("HERE! on_addFramesEnd_valueChanged %d", arg1);
}

/**
 * Signal for when the value for the start frame box associated with add frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_addFramesStart_valueChanged(int arg1)
{
	qDebug("HERE! on_addFramesStart_valueChanged %d", arg1);
}

/**
 * Signal for when the button associated with add frames is clicked
 */
void Toolbox::on_addFramesButton_clicked()
{
	qDebug("HERE! on_addFramesButton_clicked");
}

/**
 * Signal for when the value for the start frame box associated with remove frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_removeFramesStart_valueChanged(int arg1)
{
	qDebug("HERE! on_removeFramesStart_valueChanged %d", arg1);
}

/**
 * Signal for when the value for the end frame box associated with remove frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_removeFramesEnd_valueChanged(int arg1)
{
	qDebug("HERE! on_removeFramesEnd_valueChanged %d", arg1);
}

/**
 * Signal for when the button associated with remove frames is clicked
 */
void Toolbox::on_removeFramesButton_clicked()
{
	qDebug("HERE! on_removeFramesButton_clicked");
}

/**
 * Signal for when the value for the start frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesStart_valueChanged(int arg1)
{
	qDebug("HERE! on_copyFramesStart_valueChanged %d", arg1);
}

/**
 * Signal for when the value for the end frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesEnd_valueChanged(int arg1)
{
	qDebug("HERE! on_copyFramesEnd_valueChanged %d", arg1);
}

/**
 * Signal for when the value for the index frame box associated with copy frames is changed
 * @param An integer value of what the number has been changed to
 */
void Toolbox::on_copyFramesIndex_valueChanged(int arg1)
{
	qDebug("HERE! on_copyFramesIndex_valueChanged %d", arg1);
}

/**
 * Signal for when the button associated with copy frames is clicked
 */
void Toolbox::on_copyFramesButton_clicked()
{
	qDebug("HERE! on_copyFramesButton_clicked");
}

/**
 * Signal for when the value for the current time box associated with time intervals is changed
 * @param A QTime value of what the time has been changed to
 */
void Toolbox::on_currentTime_timeChanged(QTime timeVal) {
	qDebug("HERE! on_currentTime_timeChanged %d:%d:%d", timeVal.minute(), timeVal.second(), timeVal.msec());
}

/**
 * Signal for when the value for the interval time box associated with time intervals is changed
 * @param A QTime value of what the time has been changed to
 */
void Toolbox::on_timeInterval_timeChanged(QTime timeVal) {
	qDebug("HERE! on_timeInterval_timeChanged %d:%d:%d", timeVal.minute(), timeVal.second(), timeVal.msec());
}

/**
 * Signal for when the the current selected color has been changed
 * @param A QColor value of what the color has been changed to
 */
void Toolbox::on_colorDialog_currentColorChanged(QColor colorVal)
{
	qDebug("HERE! on_colorDialog_currentColorChanged %d:%d:%d", colorVal.red(), colorVal.green(), colorVal.blue());
}