#include "meme.h"
#include "ui_meme.h"

Meme::Meme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Meme)
{
    ui->setupUi(this);
}

Meme::~Meme()
{
    delete ui;
}

void Meme::closeEvent(QCloseEvent *event) {
    //detect the end of life of window.
    //emit signal calling mainmenu to revive.
    emit suicided();
    event->accept();
}
