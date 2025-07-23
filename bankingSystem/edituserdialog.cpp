#include "edituserdialog.h"
#include "ui_edituserdialog.h"
#include <QString>
editUserDialog::editUserDialog(User * userToEdit,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUserDialog)
{
    ui->setupUi(this);
    this->userToEdit = userToEdit;

    ui->name_lineEdit->setText(  userToEdit->getName());
    ui->lastName_lineEdit->setText(userToEdit->getLastName());
    ui->username_lineEdit->setText(userToEdit->getUsername());
    ui->age_lineEdit->setText(QString::number(userToEdit->getAge()));
    ui->password_lineEdit->setText(userToEdit->getPassword());
    ui->nationalCode_lineEdit->setText(userToEdit->getNationalCode());

}

editUserDialog::~editUserDialog()
{
    delete ui;
}

QString editUserDialog::getName()
{
    return ui->name_lineEdit->text();
}

QString editUserDialog::getLastName()
{
    return ui->lastName_lineEdit->text();
}

QString editUserDialog::getNationalCode()
{
    return ui->nationalCode_lineEdit->text();
}

QString editUserDialog::getUsername()
{
    return ui->username_lineEdit->text();
}

QString editUserDialog::getPassword()
{
    return ui->password_lineEdit->text();
}

int editUserDialog::getAge()
{
    return ui->age_lineEdit->text().toInt();
}
