#include "lottery.h"
#include "ui_lottery.h"

Lottery::Lottery(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lottery)
{
    ui->setupUi(this);
}

Lottery::~Lottery()
{
    delete ui;
}

void Lottery::closeEvent(QCloseEvent *event) {
    //detect the end of life of window.
    //emit signal calling mainmenu to revive.
    emit suicided(3);
    event->accept();
}
