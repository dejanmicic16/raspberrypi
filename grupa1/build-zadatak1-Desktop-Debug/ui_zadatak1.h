/********************************************************************************
** Form generated from reading UI file 'zadatak1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZADATAK1_H
#define UI_ZADATAK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_zadatak1
{
public:
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QDialog *zadatak1)
    {
        if (zadatak1->objectName().isEmpty())
            zadatak1->setObjectName(QString::fromUtf8("zadatak1"));
        zadatak1->resize(800, 600);
        pushButton = new QPushButton(zadatak1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 520, 91, 30));
        horizontalSlider = new QSlider(zadatak1);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 560, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(zadatak1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 120, 741, 341));
        label->setPixmap(QPixmap(QString::fromUtf8("\":/prefix1/catSleeping.jpeg\"")));

        retranslateUi(zadatak1);

        QMetaObject::connectSlotsByName(zadatak1);
    } // setupUi

    void retranslateUi(QDialog *zadatak1)
    {
        zadatak1->setWindowTitle(QCoreApplication::translate("zadatak1", "zadatak1", nullptr));
        pushButton->setText(QCoreApplication::translate("zadatak1", "PushButton", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class zadatak1: public Ui_zadatak1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZADATAK1_H
