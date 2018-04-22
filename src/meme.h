#ifndef MEME_H
#define MEME_H

#include <QCloseEvent>
#include <QMainWindow>

namespace Ui {
class Meme;
}

class Meme : public QMainWindow
{
    Q_OBJECT

signals:
    void suicided();

public:
    explicit Meme(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Meme();

private:
    Ui::Meme *ui;
};

#endif // MEME_H
