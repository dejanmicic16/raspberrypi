#include "dialog.h"




Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);
    /*QTimer *myTimer1 = new QTimer(this);
        connect(myTimer1, SIGNAL(timeout()), this, SLOT(ReadTimeSlot()));
        //connect(myTimer1, SIGNAL(timeout()), this, SLOT(on_checkBox_stateChanged(int arg1));
        myTimer1->start(1000);*/

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ReadTimeSlot()
{
    /*char devname_head[100] =
        "/sys/devices/w1_bus_master1/28-00000a401e35/w1_slave";
    if ((fd = fopen(dev_name, O_RDONLY)) < 0)
        {
            perror("Greška pri otvaranju!");
            exit(1);
        }
        ret = read(fd, buffer, sizeof(buffer));

        if (ret < 0)
        {
            perror("Greška pri čitanju!");
            exit(1);
        }*/
}

