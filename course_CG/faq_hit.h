#ifndef FAQ_HIT_H
#define FAQ_HIT_H

#include <QDialog>

namespace Ui {
class FAQ_Hit;
}

class FAQ_Hit : public QDialog
{
    Q_OBJECT

public:
    explicit FAQ_Hit(QWidget *parent = nullptr);
    ~FAQ_Hit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FAQ_Hit *ui;
};

#endif // FAQ_HIT_H
