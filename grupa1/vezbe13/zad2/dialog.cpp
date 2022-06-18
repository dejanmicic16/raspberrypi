#include "dialog.h"
#include "ui_dialog.h"

int fd, adcVal;
const char PCF8591 = 0x48;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QTimer *myTimer1 = new QTimer(this);
            connect(myTimer1, SIGNAL(timeout()), this, SLOT(ReadTimeSlot()));
            //connect(myTimer1, SIGNAL(timeout()), this, SLOT(on_checkBox_stateChanged(int arg1));
            myTimer1->start(1000);
            ui->dial->setDisabled(true);
            ui->verticalSlider->setDisabled(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::ReadTimeSlot()
{
    if (wiringPiSetup () == -1) exit (1);
    fd = wiringPiI2CSetup(PCF8591);

    wiringPiI2CReadReg8(fd, PCF8591 + 0) ; // dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 0) ;
    ui->lcdNumber->display(adcVal);

    wiringPiI2CReadReg8(fd, PCF8591 + 3) ; // dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 3) ;
    ui->dial->setValue(adcVal);

    wiringPiI2CReadReg8(fd, PCF8591 + 2) ; // dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 2) ;
    ui->verticalSlider->setValue(adcVal);

}
