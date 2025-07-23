#include "logindialog.h"
#include "AdminDashboard.h"
#include "CustomerDashboard.h"


#include "LinkedList.h"
#include "user.h"
#include "admin.h"
#include "customer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LinkedList<User*> allUsers;

    Admin *admin1 = new Admin("ali","slh","123","ali84","1234",20);
    Customer *customer1 = new Customer("a","pp","888","aaa","0000",77);
    Customer *customer2 = new Customer("b","pp","888","bbb","1111",77);
    allUsers.insertAtEnd(admin1);
    allUsers.insertAtEnd(customer1);
    allUsers.insertAtEnd(customer2);

    //add account for test
    admin1->addAccountToCustomer(customer1,1,100000);
    admin1->addAccountToCustomer(customer2,1,500000);
    admin1->addAccountToCustomer(customer1,2,900000);
    admin1->addAccountToCustomer(customer2,2,400000);


    //...
    qDebug() << "--- DEBUG: ALL ACCOUNTS FOR TESTING ---";
    Node<User*>* userNode = allUsers.getHead();
    while(userNode != nullptr)
    {
        Customer* customer = dynamic_cast<Customer*>(userNode->data);
        if (customer) {
            Node<Account*>* accountNode = customer->getAccounts().getHead();
            while(accountNode != nullptr)
            {
                qDebug() << "Owner:" << customer->getUsername()
                         << "| Card Number:" << accountNode->data->getCardNumber()<<"| Pin2:"<<accountNode->data->getPin2();
                accountNode = accountNode->next;
            }
        }
        userNode = userNode->next;
    }
    qDebug() << "-----------------------------------------";



    while(true)
    {
        LoginDialog loginDialog(&allUsers);

        if(loginDialog.exec() == QDialog::Accepted)
        {
            User *user = loginDialog.getLogUser();
            if(dynamic_cast<Admin*>(user) != nullptr)
            {
                Admin* admin=dynamic_cast<Admin*>(user);
                AdminDashboard *adminWindow = new AdminDashboard(&allUsers,admin);
                adminWindow->show();
                a.exec();
            }

            else if(dynamic_cast<Customer*>(user) != nullptr)
            {
                Customer* customer = dynamic_cast<Customer*>(user);
                CustomerDashboard *customerWindow = new CustomerDashboard(&allUsers,customer);
                customerWindow->show();
                a.exec();
            }
        }
        else
        {
            break;
        }
    }


    return a.exec();
}
