#include "faq_move.h"
#include "ui_faq_move.h"

FAQ_Move::FAQ_Move(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FAQ_Move)
{
    ui->setupUi(this);
}

FAQ_Move::~FAQ_Move()
{
    delete ui;
}

void FAQ_Move::on_pushButton_clicked()
{
    this->close();
}
