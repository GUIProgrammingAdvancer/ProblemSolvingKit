#ifndef LOTTERY_H
#define LOTTERY_H

#include <QCloseEvent>
#include <QMainWindow>

namespace Ui {
class Lottery;
}

class Lottery : public QMainWindow
{
    Q_OBJECT

signals:
    void suicided();

public:
    explicit Lottery(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Lottery();

private:
    Ui::Lottery *ui;
};

#endif // LOTTERY_H
