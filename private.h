#ifndef PRIVATE_H
#define PRIVATE_H

#include <QDialog>

namespace Ui {
class Private;
}

class Private : public QDialog
{
    Q_OBJECT

public:
    explicit Private(QWidget *parent = nullptr);
    ~Private();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Private *ui;
};

#endif // PRIVATE_H
