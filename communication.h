#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QDialog>

namespace Ui {
class Communication;
}

class Communication : public QDialog
{
    Q_OBJECT

public:
    explicit Communication(QWidget *parent = nullptr);
    ~Communication();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Communication *ui;
};

#endif // COMMUNICATION_H
