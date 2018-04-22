#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <QCloseEvent>
#include <QMainWindow>

namespace Ui {
class Assistant;
}

class Assistant : public QMainWindow
{
    Q_OBJECT

signals:
    void suicided();

public:
    explicit Assistant(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Assistant();

private:
    Ui::Assistant *ui;
};

#endif // ASSISTANT_H
