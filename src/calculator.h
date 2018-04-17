#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QCloseEvent>
#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

signals:
    void suicided();

public:
    explicit Calculator(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Calculator();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
