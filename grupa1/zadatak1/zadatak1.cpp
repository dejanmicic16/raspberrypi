#include "zadatak1.h"
#include "ui_zadatak1.h"


zadatak1::zadatak1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zadatak1)
{
    ui->setupUi(this);


}

zadatak1::~zadatak1()
{
    delete ui;
}


void zadatak1::on_pushButton_clicked()
{
    digitalWrite(25, HIGH);
}

void zadatak1::on_horizontalSlider_valueChanged(int value)
{
    fflush(stdout);
    softPwmWrite(28, value);
}

void zadatak1::on_pushButton_clicked(bool checked)
{
    if(checked)
    {
        ui->label->setPixmap(QPixmap(":/prefix1/catSleeping.jpeg"));
    }
    else
    {
        ui->label->setPixmap(QPixmap(":/prefix1/catAwaik.jpeg"));
    }
}
