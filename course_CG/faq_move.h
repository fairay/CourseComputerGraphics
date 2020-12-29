#ifndef FAQ_MOVE_H
#define FAQ_MOVE_H

#include <QDialog>

namespace Ui {
class FAQ_Move;
}

class FAQ_Move : public QDialog
{
    Q_OBJECT

public:
    explicit FAQ_Move(QWidget *parent = nullptr);
    ~FAQ_Move();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FAQ_Move *ui;
};

#endif // FAQ_MOVE_H
