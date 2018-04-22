#include "meme.h"
#include "ui_meme.h"

Meme::Meme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Meme)
{
    ui->setupUi(this);

    connect(ui->btn_LoadLocalMeme, SIGNAL(clicked(bool)), this, SLOT(loadLocalMeme()));
    connect(ui->btn_ChangeFont, SIGNAL(clicked(bool)), this, SLOT(changeFont(bool)));
    connect(ui->btn_ChangeColor, SIGNAL(clicked(bool)), this, SLOT(changeColor()));
    connect(ui->btn_SaveMeme, SIGNAL(clicked(bool)), this, SLOT(saveMeme()));
    connect(ui->btn_CopyMeme, SIGNAL(clicked(bool)), this, SLOT(copyMeme()));
    connect(ui->txt_MemeText, SIGNAL(textChanged(QString)), this, SLOT(changeText(QString)));
    connect(ui->xSlider, SIGNAL(valueChanged(int)), this, SLOT(changeXPos(int)));
    connect(ui->ySlider, SIGNAL(valueChanged(int)), this, SLOT(changeYPos(int)));

    MemeButton *btn;
    QIcon *ico;
    for(int i = 0; i < 33; i++){
        btn = new MemeButton(i);
        ico = new QIcon(":/res/meme/" + QString::number(i) + ".png");\
        btn->setObjectName(QString("btn_MyMeme_") + QString::number(i));
        btn->setText(QString(""));
        btn->setIcon(*ico);
        btn->setIconSize(QSize(64,64));
        ui->memeList->addWidget(btn,i/3,i%3);
        btn->show();
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(loadMyMeme()));
    }
}

Meme::~Meme()
{
    delete ui;
}

void Meme::closeEvent(QCloseEvent *event) {
    //detect the end of life of window.
    //emit signal calling mainmenu to revive.
    emit suicided(4);
    event->accept();
}

void Meme::loadMyMeme(){
    ui->statusbar->showMessage(QString("Loading ") + sender()->objectName(), 1000);
    delete memeImage;
    memeImage = new QImage(":/res/meme/" + QString::number(((MemeButton*)sender())->memeID) + ".png");

    changeXPos(ui->xSlider->sliderPosition());
    changeYPos(ui->ySlider->sliderPosition());
    updateMeme();

    ui->txt_MemeText->setEnabled(true);
    ui->xSlider->setEnabled(true);
    ui->ySlider->setEnabled(true);
    ui->btn_ChangeFont->setEnabled(true);
    ui->btn_ChangeColor->setEnabled(true);
    ui->btn_SaveMeme->setEnabled(true);
    ui->btn_CopyMeme->setEnabled(true);
}

void Meme::loadLocalMeme() {
   QString *memePath = new QString(QFileDialog::getOpenFileName(
         this, QString("Select meme source"), "", "Image Files(*.jpg *.png)", 0, 0));
   ui->statusbar->showMessage(QString("Loading ") + memePath, 1000);

   if(memePath->isEmpty()){
       QMessageBox::information(this, QString("Warning"), QString("No file selected."));
       ui->txt_MemeText->setEnabled(false);
       ui->xSlider->setEnabled(false);
       ui->ySlider->setEnabled(false);
       ui->btn_ChangeFont->setEnabled(false);
       ui->btn_ChangeColor->setEnabled(false);
       ui->btn_SaveMeme->setEnabled(false);
       ui->btn_CopyMeme->setEnabled(false);
       return;
   }

   memeImage->load(*memePath);
   delete memePath;

   changeXPos(ui->xSlider->sliderPosition());
   changeYPos(ui->ySlider->sliderPosition());
   updateMeme();

   ui->txt_MemeText->setEnabled(true);
   ui->xSlider->setEnabled(true);
   ui->ySlider->setEnabled(true);
   ui->btn_ChangeFont->setEnabled(true);
   ui->btn_ChangeColor->setEnabled(true);
   ui->btn_SaveMeme->setEnabled(true);
   ui->btn_CopyMeme->setEnabled(true);
}

void Meme::changeFont(bool ok){
    *memeFont = QFontDialog::getFont(&ok);
    updateMeme();
}

void Meme::changeColor(){
    *memeColor = QColorDialog::getColor(Qt::black);
    updateMeme();
}

void Meme::changeText(QString text) {
    *memeText = text;
    updateMeme();
}

void Meme::changeXPos(int x) {
    *posx = memeImage->width()*x/100;
    updateMeme();
}

void Meme::changeYPos(int y) {
    *posy = memeImage->height()*y/100;
    updateMeme();
}

void Meme::updateMeme() {
    if(memeImage->isNull()){
        ui->statusbar->showMessage(QString("No image loaded. Abort."), 300);
        return;
    }

    *memePix = QPixmap::fromImage(*memeImage);
    QPainter *memePainter = new QPainter(memePix);
    memePainter->setPen(*memeColor);
    memePainter->setFont(*memeFont);

    memePainter->drawText(QPoint(*posx, *posy), *memeText);
    ui->memeView->setPixmap(*memePix);
    memePainter->end();
    delete memePainter;

    ui->statusbar->showMessage(QString("Painted ") + *memeText
         + QString(" at (") + QString::number(*posx)
         + QString(", ") + QString::number(*posy) + QString(")."), 300);
}

void Meme::saveMeme() {
    QString *savePath = new QString(QFileDialog::getSaveFileName(
                        this, QString("Select destination"), "", "Image Files(*.jpg *.png)",0,0));
    ui->statusbar->showMessage(QString("Saving to ") + savePath, 1000);

    if(savePath->isEmpty()){
        QMessageBox::information(this, QString("Warning"), QString("No destination selected."));
        return;
    }

    memePix->save(*savePath);
    delete savePath;
}

void Meme::copyMeme() {
    QClipboard *cpboard = QApplication::clipboard();
    cpboard->setPixmap(*memePix);
    ui->statusbar->showMessage(QString("Copyed to clipboard."), 1000);
}
