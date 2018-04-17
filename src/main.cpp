#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);
    MainMenu *w = new MainMenu;

    a->connect(w, SIGNAL(suiciding()), a, SLOT(quit()));
    w->show();

    return a->exec();
}
