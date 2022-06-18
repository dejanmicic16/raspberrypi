#ifndef DIALOG_H
#define DIALOG_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <QTime>
#include <QTimer>
#include <QDialog>

int fd = -1, ret;
char buffer[100];

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void ReadTimeSlot();
private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
