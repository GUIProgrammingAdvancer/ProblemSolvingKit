#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
    //connect signals and slots to summon apps
    connect(ui->button_assistant, SIGNAL(clicked(bool)), this, SLOT(summonAssistant()));
    connect(ui->button_calculator, SIGNAL(clicked(bool)), this, SLOT(summonCalculator()));
    connect(ui->button_lottery, SIGNAL(clicked(bool)), this, SLOT(summonLottery()));
    connect(ui->button_meme, SIGNAL(clicked(bool)), this, SLOT(summonMeme()));
    connect(ui->button_exit, SIGNAL(clicked(bool)), this, SLOT(suicide()));

    //connect s&s to recall menu ui when app suicides
    connect(this->myAssistant, SIGNAL(suicided()), this, SLOT(revive()));
    connect(this->myCalculator, SIGNAL(suicided()), this, SLOT(revive()));
    connect(this->myLottery, SIGNAL(suicided()), this, SLOT(revive()));
    connect(this->myMeme, SIGNAL(suicided()), this, SLOT(revive()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::summonAssistant(){
    //summon assistant ui and hide main menu
    this->myAssistant->show();
    this->hide();
}

void MainMenu::summonCalculator(){
    this->myCalculator->show();
    this->hide();
}

void MainMenu::summonLottery(){
    this->myLottery->show();
    this->hide();
}

void MainMenu::summonMeme(){
    this->myMeme->show();
    this->hide();
}

void MainMenu::revive(){
    //show main menu again
    this->show();
}

void MainMenu::suicide(){
    //end of life
    //emit signal to trigger suicide of QApplication.
    emit suiciding();
}
