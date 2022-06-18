#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(25,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
