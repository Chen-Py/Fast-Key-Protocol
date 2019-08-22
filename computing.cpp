#include "computing.h"
#include "main_algorithm.h"
#include "ui_computing.h"

computing::computing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computing)
{
    ui->setupUi(this);
}
CPY kalgo;
computing::~computing()
{
    delete ui;
}
bool kpb_3=0,kpb_2=0;
void computing::on_pushButton_2_clicked()
{
    if(kpb_2)return;
    kpb_2=1;
    ui->pushButton_2->setText("Submitted");
    kalgo.P=ui->lineEdit_26->text().toLongLong();
    return;
}

void computing::on_pushButton_3_clicked()
{
    if(kpb_3)return;
    kpb_3=1;
    ui->pushButton_3->setText("Submitted");
    long long cod;
    cod=ui->lineEdit_29->text().toLongLong();
    int cnt=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            kalgo.Qs.m[i][j]=(cod&((long long)3<<(cnt*2)))>>(cnt*2);
            cnt++;
        }
    }
    kalgo.Step_3();
    kalgo.Step_4();
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(kalgo.key[i][j])
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
