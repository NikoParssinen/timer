#include "mainwindow.hh"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug("what");
    ui->setupUi(this);
    qDebug("is");
    timer = new QTimer(this);
    qDebug("going");
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    qDebug("on");
    timer->start(1000);
    qDebug("here");

}

MainWindow::~MainWindow()
{
    qDebug("fishy stuff");
    delete ui;
    delete timer;
}

void MainWindow::on_startButton_clicked()
{
    qDebug("started");
    started = true;
}

void MainWindow::on_resetButton_clicked()
{
    qDebug("i");
    sec_ = 0;
    min_ = 0;
    qDebug("dont");
    ui->lcdNumberSec->display(sec_);
    ui->lcdNumberMin->display(min_);
    qDebug("understand");
}

void MainWindow::update() {
    qDebug("where");
    if(started == true) {
        sec_ += 1;
        qDebug("did");
        if(sec_ == 60) {
            qDebug("you");
            sec_ = 0;
            min_ += 1;
        }
        qDebug("crash");
        ui->lcdNumberSec->display(sec_);
        ui->lcdNumberMin->display(min_);
    }
    qDebug("Weird!!!");
}

