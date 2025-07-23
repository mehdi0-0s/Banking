#ifndef EDITUSERDIALOG_H
#define EDITUSERDIALOG_H

#include <QDialog>
#include "user.h"
namespace Ui {
class editUserDialog;
}

class editUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editUserDialog(User * userToEdit,QWidget *parent = nullptr);
    ~editUserDialog();

    QString getName();
    QString getLastName();
    QString getNationalCode();
    QString getUsername();
    QString getPassword();
    int getAge();

private:
    Ui::editUserDialog *ui;
    User * userToEdit;
};

#endif // EDITUSERDIALOG_H
