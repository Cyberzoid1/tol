#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>

namespace Ui {
class ToolBox;
}

class ToolBox : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBox(QWidget *parent = 0);
    ~ToolBox();

private slots:
    void on_redBox_valueChanged(int arg1);

    void on_greenBox_valueChanged(int arg1);

    void on_blueBox_valueChanged(int arg1);

    void on_redSlider_valueChanged(int value);

    void on_greenSlider_valueChanged(int value);

    void on_blueSlider_valueChanged(int value);

    void on_colorHex_returnPressed();

    void on_addFrameStart_valueChanged(int arg1);

    void on_addFrameAmount_valueChanged(int arg1);

    void on_addFrameConfirm_clicked();

    void on_removeFrameFirst_valueChanged(int arg1);

    void on_removeFrameLast_valueChanged(int arg1);

    void on_removeFrameConfirm_clicked();

    void on_copyFrameSourceIndex_valueChanged(int arg1);

    void on_copyFrameDestinationIndex_valueChanged(int arg1);

    void on_copyFrameConfirmation_clicked();

private:
    Ui::ToolBox *ui;
};

#endif // TOOLBOX_H
