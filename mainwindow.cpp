#include "mainwindow.h"
#include "ui_mainwindow.h"

int check=0;
QString datedisplay;
QString timedisplay;
QString alldiaplay;
QString ctime;
QString cdate;
QDateTime settime;
QDateTime time2;
QString alarmtime;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec *codec = QTextCodec::codecForName("Big5");
    ui->setupUi(this);

    clock = new QTimer;
    clock ->setInterval(1000);
    connect(clock,SIGNAL(timeout()),this,SLOT(updateTime()));
    clock->start();


    QFile file ("time.txt");
    if(file.open(QIODevice::ReadOnly)){
        QString line;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
            ui->time->append(line);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    ui->time->clear();
    ui->time->append(datedisplay);
    //remindtime=
    QFile file ("time.txt");
    if(file.open(QFile::WriteOnly |QFile::Truncate | QFile::Text)){
        QTextStream out(&file);
        out<<ui->time->document()->toPlainText()<<endl;
    }
    QFile file2 ("text.txt");
    if(file2.open(QFile::WriteOnly |QFile::Truncate| QFile::Text)){
        QTextStream out(&file2);
        out<<ui->textEdit->toPlainText()<<endl;
    }
}


void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    check++;
    time2=dateTime;
    datedisplay=dateTime.toString("yyyy-M-d hh:mm");
    settime=time2.addSecs(-1800);
    alarmtime=settime.toString("yyyy-M-d hh:mm");
    if(check>0){
        ui->add->setEnabled(true);
    }
}
void MainWindow::updateTime()
{
    QTime time;
    QDateTime date;
    time = time.currentTime();
    date = date.currentDateTime();
    ctime=time.toString("hh:mm");
    cdate=date.toString("yyyy-M-d");
    qDebug()<<cdate+" "+ctime;
    if(cdate+" "+ctime==alarmtime)
    {
        qDebug()<<alarmtime;
        qDebug()<<"YES";
        ui->alarm->clear();

            QFile file2 ("text.txt");
            if(file2.open(QIODevice::ReadOnly)){
                QString line;
                QTextStream in(&file2);
                while (!in.atEnd()){
                    line=in.readLine();
                    ui->alarm->append(line);
                }
            }
    }
}
