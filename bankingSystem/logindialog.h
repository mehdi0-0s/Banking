#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "user.h"
#include "LinkedList.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(LinkedList<User*> *allUsers,QWidget *parent = nullptr);
    ~LoginDialog();
    User* getLogUser();

private slots:
    void on_login_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    LinkedList<User*> *allUsers;
    User *logUser;
};

#endif // LOGINDIALOG_H
