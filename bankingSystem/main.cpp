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

    Admin *admin1 = new Admin("mehdi","salahshouri","1160623163","mehdi84","1234",20);
    Admin *admin2 = new Admin("mahan","hashemi","116588978","mahan89h","m1234",30);
    Customer *customer1 = new Customer("ali","salehi","1170596856","ali54s","0000",54);
    Customer *customer2 = new Customer("negar","hoseini","1160665696","negar1","1111",39);
    allUsers.insertAtEnd(admin1);
    allUsers.insertAtEnd(admin2);
    allUsers.insertAtEnd(customer1);
    allUsers.insertAtEnd(customer2);

    //add account for test
    admin1->addAccountToCustomer(customer1,1,100000);
    admin1->addAccountToCustomer(customer2,1,5000000);
    admin1->addAccountToCustomer(customer1,2,9000000);
    admin1->addAccountToCustomer(customer2,2,400000);



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
                adminWindow->setAttribute(Qt::WA_DeleteOnClose);
                adminWindow->show();
                a.exec();
            }

            else if(dynamic_cast<Customer*>(user) != nullptr)
            {
                Customer* customer = dynamic_cast<Customer*>(user);
                CustomerDashboard *customerWindow = new CustomerDashboard(&allUsers,customer);
                customerWindow->setAttribute(Qt::WA_DeleteOnClose);
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
