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
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)
public:
    explicit Toolbox(QWidget *parent = 0);
    ~Toolbox();

    QColor color() const
    {
        return m_color;
    }
    void showColor();

signals:
    void colorChanged(QColor color);

private slots:
    void onColorChange();

private:
    Ui::Toolbox *ui;

    QColor m_color;
};

#endif // TOOLBOX_H
