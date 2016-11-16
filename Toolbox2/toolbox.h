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

private:
    Ui::Toolbox *ui;
};

#endif // TOOLBOX_H
