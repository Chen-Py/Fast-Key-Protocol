#include "communication.h"
#include <main_algorithm.h>
#include "ui_communication.h"
#include "cstring"
bool cpb_2=0,cpb_3=0;
CPY algo;
Communication::Communication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Communication)
{
    ui->setupUi(this);
}

Communication::~Communication()
{
    delete ui;
}

void Communication::on_pushButton_2_clicked()
{
    if(cpb_2)return;
    cpb_2=1;
    ui->pushButton_2->setText("Submitted");
    std::string str;
    QString temp;
    temp=ui->lineEdit_26->text();
    str=temp.toStdString();
    int N=0;
    long long P=0;
    int i;
    for(i=1;i<((int)str.size())-1;i++)
    {
        if(str[i]==',')break;
        N=N*10+str[i]-'0';
    }
    for(;i<((int)str.size())-1;i++)
    {
        if(str[i]==',')continue;
        P=P*10+str[i]-'0';
    }
    algo.Step_1(N);
    int cnt=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            algo.Qs.m[i][j]=(P&((long long)3<<(cnt*2)))>>(cnt*2);
            cnt++;
        }
    }
    return;
}

void Communication::on_pushButton_3_clicked()
{
    if(cpb_3)return;
    cpb_3=1;
    ui->pushButton_3->setText("Submitted");
    long long q;
    q=ui->lineEdit_29->text().toLongLong();
    algo.Step_2(q);
    algo.Step_3();
    algo.Step_4();
    long long Q=0,cnt=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            Q|=((long long)algo.Ps.m[i][j]<<(cnt*2));
            cnt++;
        }
    }
    ui->textBrowser->textCursor().insertText("The Communication open code is:\n"+QString::number(Q)+"\nPlease send it to the receiver\n-------------------------------\nThe Communication secret code is:\n"+QString::number(q)+"\nPlease keep it secret");
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(algo.key[i][j])
                ui->textBrowser_3->textCursor().insertText("1");
            else
                ui->textBrowser_3->textCursor().insertText("0");
            if(j==10)break;
            ui->textBrowser_3->textCursor().insertText(" ");
        }
        if(i==10)break;
        ui->textBrowser_3->textCursor().insertText("\n");
    }
}



