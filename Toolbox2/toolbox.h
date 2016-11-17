#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QColor>

namespace Ui {
class Toolbox;
}

class Toolbox : public QWidget
{
    Q_OBJECT

public:
    explicit Toolbox(QWidget *parent = 0);
    ~Toolbox();

signals:

private slots:

    void on_addFramesEnd_valueChanged(int arg1);

    void on_addFramesStart_valueChanged(int arg1);

    void on_addFramesButton_clicked();

    void on_removeFramesStart_valueChanged(int arg1);

    void on_removeFramesEnd_valueChanged(int arg1);

    void on_removeFramesButton_clicked();

    void on_copyFramesStart_valueChanged(int arg1);

    void on_copyFramesEnd_valueChanged(int arg1);

    void on_copyFramesIndex_valueChanged(int arg1);

    void on_copyFramesButton_clicked();

    void colorChanged();

private:
    Ui::Toolbox *ui;
};

#endif // TOOLBOX_H
