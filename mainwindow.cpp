#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "workthread.h"

#include <QMessageBox>
#include<QDebug>
#include <QDateTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/resource/qss/pushButton/pseudoStates.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString ssl = filetext.readAll();
    file.close();


    ui->pushButton->setStyleSheet(ssl); //
    ui->pushButton_QthreadTest->setStyleSheet(ssl); //
    ui->pushButton_qss->setStyleSheet(ssl); //

    ui->pushButton->setCheckable(true);                 //设置按钮是否可以被选中。
    ui->pushButton_QthreadTest->setCheckable(true);     //设置按钮是否可以被选中。
    ui->pushButton_qss->setCheckable(true);             //设置按钮是否可以被选中。


    //同一父部件的可选中按钮中，‌设置了自动排他性
    ui->pushButton->setAutoExclusive(true);
    ui->pushButton_QthreadTest->setAutoExclusive(true);
    ui->pushButton_qss->setAutoExclusive(true);

    ui->pushButton_QthreadTest->setChecked(true);//


}

MainWindow::~MainWindow()
{
    delete ui;



}

void MainWindow::on_pushButton_clicked()
{
    // QMessageBox::StandardButton button  = QMessageBox::information(nullptr, "information", "是否退出窗口",
    //                                                               QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);
    // if (button == QMessageBox::StandardButton::Yes) {
    //     qDebug() << "QMessageBox::StandardButton::Yes";
    // } else if (button == QMessageBox::StandardButton::No) {
    //     qDebug() << "QMessageBox::StandardButton::No";
    // }

    // testMap();

    // 三个按钮都放在了一个groupBox中，每个setCheckable(bool): 设置按钮是否可以被选中。
   // ui->pushButton->setChecked(true);//

}


void MainWindow::testMap(){

    std::map<int,std::string> map;

    map[0] = "first";
    map[1] = "second";


    std::string value1 = map[0];

    std::string value2 = map[1];

    qDebug().noquote().nospace()<<QString::fromLocal8Bit(value1)<<QString::fromLocal8Bit(value2);



}

void MainWindow::on_pushButton_QthreadTest_clicked()
{

     //ui->pushButton_QthreadTest->setChecked(true);//


    WorkThread *workThread = new WorkThread() ;

    connect(workThread,&QThread::started ,this,&MainWindow::onQThreadStarted);
    connect(workThread,&QThread::finished ,this,&MainWindow::onQThreadFinished);



    qDebug()<<"WorkThread ----01-----  isRunning:"
             <<workThread->isRunning()<<",isFinished:"<<workThread->isFinished();

    workThread->start();

    qDebug()<<"WorkThread ----02-----  isRunning:"
             <<workThread->isRunning()<<",isFinished:"<<workThread->isFinished();

    QThread::msleep(1000);
    qDebug()<<"WorkThread ----03-----  isRunning:"
             <<workThread->isRunning()<<",isFinished:"<<workThread->isFinished();

    //workThread->quit();
    workThread->wait();

    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug().noquote().nospace()<<"["<< dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz")<<"]";

   qDebug()<<"WorkThread ----04-----  isRunning:"
             <<workThread->isRunning()<<",isFinished:"<<workThread->isFinished();



    delete workThread; //不删除也没关系

}

// 工作线程结束后的通知
void MainWindow::onQThreadStarted()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug().noquote().nospace()<<"["<< dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz")<<"]"
                                 <<" WorkThread Started!";

}

// 工作线程结束后的通知
void MainWindow::onQThreadFinished()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug().noquote().nospace()<<"["<< dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz")<<"]"
                                <<" WorkThread finish!";

}


