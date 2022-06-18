#include "zadatak1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(25,OUTPUT);
    pinMode(26,OUTPUT);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
        if(softPwmCreate(28,0,100)!=0)
            exit(2);
    QApplication a(argc, argv);
    zadatak1 w;
    w.show();
    return a.exec();
}
