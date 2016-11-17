#include "toolbox.h"
#include "ui_toolbox.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::on_redBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void ToolBox::on_greenBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void ToolBox::on_blueBox_valueChanged(int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    else if (arg1 > 255) {
        arg1 = 255;
    }
}

void ToolBox::on_redSlider_valueChanged(int value)
{

}

void ToolBox::on_greenSlider_valueChanged(int value)
{

}

void ToolBox::on_blueSlider_valueChanged(int value)
{

}

void ToolBox::on_colorHex_returnPressed()
{

}

void ToolBox::on_addFrameStart_valueChanged(int arg1)
{

}

void ToolBox::on_addFrameAmount_valueChanged(int arg1)
{

}

void ToolBox::on_addFrameConfirm_clicked()
{

}

void ToolBox::on_removeFrameFirst_valueChanged(int arg1)
{

}

void ToolBox::on_removeFrameLast_valueChanged(int arg1)
{

}

void ToolBox::on_removeFrameConfirm_clicked()
{

}

void ToolBox::on_copyFrameSourceIndex_valueChanged(int arg1)
{

}

void ToolBox::on_copyFrameDestinationIndex_valueChanged(int arg1)
{

}

void ToolBox::on_copyFrameConfirmation_clicked()
{

}
