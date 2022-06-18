#include "dialog.h"
#include "ui_dialog.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int start_stop = 0 ;

int brojac_pol = 0 ;
int brojac_vr = 0 ;
int fd, adcVal;
const char PCF8591 = 0x48;

QLineSeries *series;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    series = new QLineSeries();
    QTimer *myTimer1 = new QTimer(this);
            connect(myTimer1, SIGNAL(timeout()), this, SLOT(ReadTimeSlot()));
            //connect(myTimer1, SIGNAL(timeout()), this, SLOT(on_checkBox_stateChanged(int arg1));
            myTimer1->start(1000);
    //* << QPointF(4,2) << QPointF(5,1);



    QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->axisX()->setRange(0,5);
        chart->axisX()->setTitleText("vreme");
        chart->axisY()->setTitleText("napon");
        chart->axisY()->setRange(0,3.3);
        chart->setTitle("Merenje napona");

    QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->verticalLayout->addWidget(chartView);



}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ReadTimeSlot()
{
    if (wiringPiSetup () == -1) exit (1);
    fd = wiringPiI2CSetup(PCF8591);

    wiringPiI2CReadReg8(fd, PCF8591 + 3) ; // dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 3) ;
    double adcVald = (double(adcVal) / 255) * 3.3;
    //ui->dial->setValue(adcVal);

    if (start_stop == 1)
    {
        *series << QPointF(brojac_pol,adcVald);
        brojac_pol++;
    }
    if(brojac_vr == 6 || start_stop == 0)
    {
        //*series << QPointF(0,0)<< QPointF(1,0)<< QPointF(2,0)<< QPointF(3,0)<< QPointF(4,0)<< QPointF(5,0);
        series->clear();
        brojac_pol = 0;
        brojac_vr = -1;
    }
    brojac_vr++;
    if(brojac_pol == 6)
    {
        brojac_pol = 0;
    }


}





void Dialog::on_pushButton_clicked()
{
    start_stop = 1;
}

void Dialog::on_pushButton_2_clicked()
{
     start_stop = 0;
}
