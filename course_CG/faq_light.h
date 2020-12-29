#ifndef FAQ_LIGHT_H
#define FAQ_LIGHT_H

#include <QDialog>

namespace Ui {
class FAQ_Light;
}

class FAQ_Light : public QDialog
{
    Q_OBJECT

public:
    explicit FAQ_Light(QWidget *parent = nullptr);
    ~FAQ_Light();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FAQ_Light *ui;
};

#endif // FAQ_LIGHT_H
