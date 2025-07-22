#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <QMainWindow>

#include "customer.h"
#include <LinkedList.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class CustomerDashboard : public QMainWindow
{
    Q_OBJECT

public:
    CustomerDashboard(LinkedList<User*>*allUsers,Customer *logCustomer,QWidget *parent = nullptr);
    ~CustomerDashboard();

private slots:
    void on_changePin_pushButton_clicked();

    void on_transfer_pushButton_clicked();

    void on_logout_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Customer *logCustomer;
    LinkedList<User*> *allUsers;
    void updateAccountsDisplay();
};
#endif // CUSTOMERDASHBOARD_H
