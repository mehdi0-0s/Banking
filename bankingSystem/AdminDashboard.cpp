#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"

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
