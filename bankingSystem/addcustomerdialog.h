#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class AddCustomerDialog;
}

class AddCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerDialog(QWidget *parent = nullptr);
    ~AddCustomerDialog();

    QString getName();
    QString getLastName();
    QString getNationalCode();
    QString getUsername();
    QString getPassword();
    int getAge();
private:
    Ui::AddCustomerDialog *ui;
};

#endif // ADDCUSTOMERDIALOG_H
