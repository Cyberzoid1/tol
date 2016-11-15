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
    connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChange()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChange()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChange()));
    showColor();
    onColorChange();
}

Toolbox::~Toolbox()
{
    delete ui;
}

void Toolbox::onColorChange()
{
    m_color.setRgb(ui->redSlider->value(), ui->greenSlider->value(), ui->blueSlider->value());
    QPalette pal = ui->displayWidget->palette();
    pal.setColor(QPalette::Window, m_color);
    ui->displayWidget->setPalette(pal);
    emit colorChanged(m_color);
}

void Toolbox::showColor()
{
    QColorDialog *dialog = new QColorDialog(ui->tab);
    dialog->setWindowFlags(Qt::Widget);
    dialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
}
