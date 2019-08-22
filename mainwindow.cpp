#include "mainwindow.h"
#include "private.h"
#include "computing.h"
#include "communication.h"
#include "ui_mainwindow.h"
#include "main_algorithm.h"
CPY cpy;
bool bt_1=0,bt_2=0,bt_3=0;
int seed;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool mpb_1=0,mpb_5=0,mpb_6=0;
void MainWindow::on_pushButton_clicked()
{
    if(mpb_1)return;
    mpb_1=1;
    ui->pushButton->setText("Done");
    Private *p = new Private(this);
    p->show();
    return;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(mpb_5)return;
    mpb_5=1;
    ui->pushButton_5->setText("Done");
    Communication *c = new Communication(this);
    c->show();
    return;
}

void MainWindow::on_pushButton_6_clicked()
{
    if(mpb_6)return;
    mpb_6=1;
    ui->pushButton_6->setText("Done");
    computing *k = new computing(this);
    k->show();
    return;
}
