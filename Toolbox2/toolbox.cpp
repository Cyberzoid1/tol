#include <QPalette>
#include <QColorDialog>
#include "toolbox.h"
#include "colorwheel.h"
#include "ui_toolbox.h"

Toolbox::Toolbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Toolbox)

{
    ui->setupUi(this);
    QColorDialog *dialog = new QColorDialog(ui->tab);
    dialog->setWindowFlags(Qt::SubWindow);
    dialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
    dialog->move(0,0);
}

Toolbox::~Toolbox()
{
    delete ui;
}
