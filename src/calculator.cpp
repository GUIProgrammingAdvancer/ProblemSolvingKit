#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::closeEvent(QCloseEvent *event) {
    //detect the end of life of window.
    //emit signal calling mainmenu to revive.
    emit suicided(2);
    event->accept();
}
