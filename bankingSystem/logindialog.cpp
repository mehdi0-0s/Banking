#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(LinkedList<User*>*allUsers,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    logUser = nullptr;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

User* LoginDialog::getLogUser()
{
    return logUser;
}


void LoginDialog::on_login_pushButton_clicked()
{
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    User* user = User::logIn(*allUsers,username,password);

    if(user != nullptr)
    {
        QMessageBox::information(this,"success","login was success");
        logUser = user;
        this->accept();
    }
    else
    {
        QMessageBox::warning(this,"failed","invalid username or password");
    }

}

