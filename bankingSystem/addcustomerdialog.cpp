#include "addcustomerdialog.h"
#include "ui_addcustomerdialog.h"

AddCustomerDialog::AddCustomerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCustomerDialog)
{
    ui->setupUi(this);
}

AddCustomerDialog::~AddCustomerDialog()
{
    delete ui;
}

QString AddCustomerDialog::getName()
{
    return ui->name_lineEdit->text();
}

QString AddCustomerDialog::getLastName()
{
    return ui->lastName_lineEdit->text();
}

QString AddCustomerDialog::getNationalCode()
{
    return ui->nationalCode_lineEdit->text();
}

QString AddCustomerDialog::getUsername()
{
    return ui->username_lineEdit->text();
}

QString AddCustomerDialog::getPassword()
{
    return ui->password_lineEdit->text();
}

int AddCustomerDialog::getAge()
{
    return ui->age_lineEdit->text().toInt();
}
