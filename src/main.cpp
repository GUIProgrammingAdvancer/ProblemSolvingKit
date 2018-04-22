#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);
    MainMenu *w = new MainMenu;

    //connect application and menu to perform suicide
    a->connect(w, SIGNAL(suiciding()), a, SLOT(quit()));

    //show the main menu and begin the program
    w->show();

    return a->exec();
}
