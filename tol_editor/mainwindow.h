#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
