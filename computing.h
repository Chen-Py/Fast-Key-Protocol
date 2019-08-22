#ifndef COMPUTING_H
#define COMPUTING_H

#include <QDialog>

namespace Ui {
class computing;
}

class computing : public QDialog
{
    Q_OBJECT

public:
    explicit computing(QWidget *parent = nullptr);
    ~computing();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::computing *ui;
};

#endif // COMPUTING_H
