#include "addaccountdialog.h"
#include "ui_addaccountdialog.h"

AddAccountDialog::AddAccountDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddAccountDialog)
{
    ui->setupUi(this);
}

AddAccountDialog::~AddAccountDialog()
{
    delete ui;
}

double AddAccountDialog::getBalance()
{
    return ui->doubleSpinBox->value();
}

int AddAccountDialog::getAccountTypeIndex()
{
    return ui->accounType_comboBox->currentIndex();
}
