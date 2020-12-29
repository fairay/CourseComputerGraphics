#include "faq_light.h"
#include "ui_faq_light.h"

FAQ_Light::FAQ_Light(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FAQ_Light)
{
    ui->setupUi(this);
}

FAQ_Light::~FAQ_Light()
{
    delete ui;
}

void FAQ_Light::on_pushButton_clicked()
{
    this->close();
}
