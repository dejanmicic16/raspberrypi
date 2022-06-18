#include "dialog.h"
#include "ui_dialog.h"

FILE *ft;
FILE * log;
char tekst[100];

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QTimer *myTimer1 = new QTimer(this);
            connect(myTimer1, SIGNAL(timeout()), this, SLOT(ReadTimeSlot()));
            //connect(myTimer1, SIGNAL(timeout()), this, SLOT(on_checkBox_stateChanged(int arg1));
            myTimer1->start(1000);
    log=fopen("log","w");
    ui->lcdNumber->setSmallDecimalPoint(true);
}

Dialog::~Dialog()
{
    fclose(log);
    delete ui;
}

void Dialog::ReadTimeSlot()
{
    ft=fopen("/sys/bus/w1/devices/28-00000a401e35/w1_slave","r");
    int i=0;

    for(i=0;i<22;i++)
        fscanf(ft,"%s", tekst);

    fclose(ft);
    for(i=0;i<10;i++) tekst[i]=tekst[i+2];

    int temp=atoi(tekst);
    double tem=(double)temp/1000;
    ui->lcdNumber->display(tem);
}
