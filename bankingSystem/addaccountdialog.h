#ifndef ADDACCOUNTDIALOG_H
#define ADDACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class AddAccountDialog;
}

class AddAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAccountDialog(QWidget *parent = nullptr);
    ~AddAccountDialog();
    double getBalance();
    int getAccountTypeIndex();
private:
    Ui::AddAccountDialog *ui;
};

#endif // ADDACCOUNTDIALOG_H
