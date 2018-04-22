#ifndef MEME_H
#define MEME_H

#include <QImage>
#include <QBrush>
#include <QVector>
#include <QPainter>
#include <QClipboard>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QCloseEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>

namespace Ui {
class Meme;
}

class MemeButton : public QPushButton
{
    Q_OBJECT

public:
    int memeID;
    MemeButton(int i):memeID(i){
        //do nothing
    }
};

class Meme : public QMainWindow
{
    Q_OBJECT

signals:
    void suicided(int);

public slots:
    void loadMyMeme();
    void loadLocalMeme();
    void changeFont(bool ok);
    void changeColor();
    void changeText(QString text);
    void changeXPos(int x);
    void changeYPos(int y);
    void saveMeme();
    void copyMeme();

public:
    explicit Meme(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Meme();

private:
    Ui::Meme *ui;
    QImage *memeImage = new QImage();
    QPixmap *memePix = new QPixmap();
    QColor *memeColor = new QColor(0,0,0,255);
    QFont *memeFont = new QFont(QString("黑体"),30,30,false);
    QString *memeText = new QString();
    int *posx = new int(0);
    int *posy = new int(0);
    void updateMeme();
};

#endif // MEME_H
