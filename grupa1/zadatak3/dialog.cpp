#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
        digitalWrite(25, HIGH);
}

void Dialog::on_pushButton_3_clicked()
{
    digitalWrite(26, HIGH);
}

void Dialog::on_pushButton_4_clicked()
{
    digitalWrite(27, HIGH);
}

void Dialog::on_pushButton_2_clicked()
{
    digitalWrite(28, HIGH);
}
