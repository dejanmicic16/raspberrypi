/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLCDNumber *lcdNumber;
    QSlider *verticalSlider;
    QDial *dial;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(160, 160, 191, 81));
        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setEnabled(true);
        verticalSlider->setGeometry(QRect(660, 110, 61, 211));
        verticalSlider->setOrientation(Qt::Vertical);
        dial = new QDial(Dialog);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setEnabled(true);
        dial->setGeometry(QRect(420, 130, 141, 121));
        dial->setMaximum(97);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
