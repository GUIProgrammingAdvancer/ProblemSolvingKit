#include "assistant.h"
#include "ui_assistant.h"

Assistant::Assistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Assistant)
{
    ui->setupUi(this);
}

Assistant::~Assistant()
{
    delete ui;
}

void Assistant::closeEvent(QCloseEvent *event) {
    //detect the end of life of window.
    //emit signal calling mainmenu to revive.
    emit suicided();
    event->accept();
}
