#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //connect signals and slots to summon apps
    connect(ui->button_assistant, SIGNAL(clicked(bool)), this, SLOT(summonAssistant()));
    connect(ui->button_calculator, SIGNAL(clicked(bool)), this, SLOT(summonCalculator()));
    connect(ui->button_lottery, SIGNAL(clicked(bool)), this, SLOT(summonLottery()));
    connect(ui->button_meme, SIGNAL(clicked(bool)), this, SLOT(summonMeme()));
    connect(ui->button_exit, SIGNAL(clicked(bool)), this, SLOT(suicide()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::summonAssistant(){
    //summon assistant ui and hide main menu
    myAssistant = new Assistant();
    connect(this->myAssistant, SIGNAL(suicided(int)), this, SLOT(revive(int)));
    this->myAssistant->show();
    this->hide();
}

void MainMenu::summonCalculator(){
    myCalculator = new Calculator();
    connect(this->myCalculator, SIGNAL(suicided(int)), this, SLOT(revive(int)));
    this->myCalculator->show();
    this->hide();
}

void MainMenu::summonLottery(){
    myLottery = new Lottery();
    connect(this->myLottery, SIGNAL(suicided(int)), this, SLOT(revive(int)));
    this->myLottery->show();
    this->hide();
}

void MainMenu::summonMeme(){
    myMeme = new Meme();
    connect(this->myMeme, SIGNAL(suicided(int)), this, SLOT(revive(int)));
    this->myMeme->show();
    this->hide();
}

void MainMenu::revive(int appID){
    switch(appID){
    case 1:
        disconnect(this->myAssistant, SIGNAL(suicided(int)), this, SLOT(revive(int)));
        delete myAssistant;
        break;
    case 2:
        connect(this->myCalculator, SIGNAL(suicided(int)), this, SLOT(revive(int)));
        delete myCalculator;
        break;
    case 3:
        connect(this->myLottery, SIGNAL(suicided(int)), this, SLOT(revive(int)));
        delete myLottery;
        break;
    case 4:
        connect(this->myMeme, SIGNAL(suicided(int)), this, SLOT(revive(int)));
        delete myMeme;
        break;
    default:
        break;
    }
    ui->statusBar->showMessage(QString("App ") + QString::number(appID) + QString(" finished."), 2000);
    //show main menu again
    this->show();
}

void MainMenu::suicide(){
    //end of life
    //emit signal to trigger suicide of QApplication.
    emit suiciding();
}
