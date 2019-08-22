#include "private.h"
#include "ui_private.h"
#include <main_algorithm.h>
CPY alg;
bool pbt_1=0,pbt_2=0,pbt_3=0;
int pseed;
Private::Private(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Private)
{
    ui->setupUi(this);
}

Private::~Private()
{
    delete ui;
}

void Private::on_pushButton_2_clicked()
{
    if(pbt_2)return;
    pbt_2=1;
    ui->pushButton_2->setText("Submitted");
    pseed=ui->lineEdit_26->text().toInt();
    alg.Step_1(pseed);
}

void Private::on_pushButton_3_clicked()
{
    if(pbt_3)return;
    pbt_3=1;
    ui->pushButton_3->setText("Submitted");
    long long p;
    p=ui->lineEdit_27->text().toLongLong();
    alg.Step_2(p);
    long long temp=0,cnt=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            temp|=((long long)alg.Ps.m[i][j]<<(cnt*2));
            cnt++;
        }
    }
    ui->textBrowser_2->textCursor().insertText("Your Private open code is:\n("+QString::number(pseed)+","+QString::number(temp)+")\nPlease publish it\n-------------------------------\nYour private secret code is:\n"+QString::number(p)+"\nPlease keep it secret");
}
