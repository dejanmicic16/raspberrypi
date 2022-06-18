#ifndef ZADATAK1_H
#define ZADATAK1_H

#include <wiringPi.h>
#include <softPwm.h>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class zadatak1; }
QT_END_NAMESPACE

class zadatak1 : public QDialog
{
    Q_OBJECT

public:
    zadatak1(QWidget *parent = nullptr);
    ~zadatak1();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked(bool checked);

private:
    Ui::zadatak1 *ui;
};
#endif // ZADATAK1_H
