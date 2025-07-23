#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>
#include "user.h"
#include "admin.h"
#include "customer.h"
#include <LinkedList.h>

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

private slots:
    void on_addCustomer_pushButton_clicked();

    void on_deleteCustomer_pushButton_clicked();

    void on_editCustomer_pushButton_clicked();

private:
    Ui::AdminDashboard *ui;
    LinkedList<User*> *allUsers;
    Admin * logAdmin;
};

#endif // ADMINDASHBOARD_H
