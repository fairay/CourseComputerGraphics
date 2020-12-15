#include "faq_hit.h"
#include "ui_faq_hit.h"

FAQ_Hit::FAQ_Hit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FAQ_Hit)
{
    ui->setupUi(this);
}

FAQ_Hit::~FAQ_Hit()
{
    delete ui;
}

void FAQ_Hit::on_pushButton_clicked()
{
    this->close();
}
