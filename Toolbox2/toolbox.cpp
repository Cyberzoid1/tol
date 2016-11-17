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
    dialog->move(0,50);
    connect(dialog, SIGNAL(currentColorChanged(QColor)), SLOT(colorChanged()));
}

Toolbox::~Toolbox()
{
    delete ui;
}

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

void Toolbox::on_copyFramesButton_clicked()
{

}

void Toolbox::colorChanged()
{

}
