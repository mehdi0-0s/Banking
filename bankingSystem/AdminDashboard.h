#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>
#include "user.h"
#include "admin.h"
#include <LinkedList.h>
#include <qlistwidget.h>

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminDashboard(LinkedList<User*> *allUsers,Admin * logAdmin,QWidget *parent = nullptr);
    ~AdminDashboard();
    void updateCustomersDisplay();
    void updateAllAccountsDisplay();

private slots:
    void on_addCustomer_pushButton_clicked();

    void on_deleteCustomer_pushButton_clicked();

    void on_editCustomer_pushButton_clicked();

    void on_addAccount_pushButton_clicked();


    void on_allAccounts_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_editMyProfile_pushButton_clicked();

    void on_print_pushButton_clicked();

private:
    Ui::AdminDashboard *ui;
    LinkedList<User*> *allUsers;
    Admin * logAdmin;
    User* findUserByUsername(QString username);
};

#endif // ADMINDASHBOARD_H
