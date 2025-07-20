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
    Customer *customer1 = new Customer("mad","pp","888","md23d","0000",77);
    allUsers.insertAtEnd(admin1);
    allUsers.insertAtEnd(customer1);




    LoginDialog loginDialog(&allUsers);
    loginDialog.show();

    if(loginDialog.exec() == QDialog::Accepted)
    {
        User *user = loginDialog.getLogUser();
        if(dynamic_cast<Admin*>(user) != nullptr)
        {
            AdminDashboard *adminWindow = new AdminDashboard();
            adminWindow->show();

        }

        else if(dynamic_cast<Customer*>(user) != nullptr)
        {
            CustomerDashboard *customerWindow = new CustomerDashboard();
            customerWindow->show();

        }
    }

    return a.exec();
}
