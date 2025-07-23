#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"
#include "addcustomerdialog.h"
#include <QMessageBox>
AdminDashboard::AdminDashboard(LinkedList<User*> *allUsers,Admin * logAdmin,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    this->logAdmin = logAdmin;

    this->updateCustomersDisplay();
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::updateCustomersDisplay()
{
    ui->customers_listWidget->clear();

    Node<User*>* current = this->allUsers->getHead();
    while (current != nullptr)
    {
        Customer* customer = dynamic_cast<Customer*>(current->data);
        if (customer)
        {
            QString customerInfo = QString("Username: %1 | Name: %2")
            .arg(customer->getUsername())
            .arg(customer->getName() + " " + customer->getLastName());
            ui->customers_listWidget->addItem(customerInfo);
        }
        current = current->next;
    }
}

void AdminDashboard::on_addCustomer_pushButton_clicked()
{
    AddCustomerDialog addDialog(this);
    if (addDialog.exec() == QDialog::Accepted)
    {
        QString name = addDialog.getName();
        QString lastName = addDialog.getLastName();
        QString nationalCode = addDialog.getNationalCode();
        QString username = addDialog.getUsername();
        QString password = addDialog.getPassword();
        int age = addDialog.getAge();

        Customer* newCustomer = this->logAdmin->createCustomer(*this->allUsers, name, lastName,
                                                                    nationalCode, username, password, age);

        if (newCustomer != nullptr) {
            QMessageBox::information(this, "موفقیت", "مشتری جدید با موفقیت اضافه شد.");
            this->updateCustomersDisplay();
        } else {
            QMessageBox::warning(this, "خطا", "نام کاربری تکراری است یا خطای دیگری رخ داد.");
        }
    }

}

