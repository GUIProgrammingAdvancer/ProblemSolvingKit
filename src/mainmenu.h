#ifndef MAINMENU_H
#define MAINMENU_H

#include "assistant.h"
#include "calculator.h"
#include "lottery.h"
#include "meme.h"
#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

signals:
    void suiciding();

private slots:
    void summonAssistant();
    void summonCalculator();
    void summonLottery();
    void summonMeme();
    void revive(int appID);
    void suicide();

private:
    Ui::MainMenu *ui;

    //applications
    Assistant *myAssistant;
    Calculator *myCalculator;
    Lottery *myLottery;
    Meme *myMeme;
};

#endif // MAINMENU_H
