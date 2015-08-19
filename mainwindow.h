#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDateTimeEdit>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include "QString"
#include <QDebug>
#include <QDateTime>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void updateTime();

private:
    Ui::MainWindow *ui;
    QTextCodec *codec;
    QTimer * clock;
};

#endif // MAINWINDOW_H
