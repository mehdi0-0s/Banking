#include "admin.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "CheckingAccount.h"
#include "QRandomGenerator"
Admin::Admin(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age)
        :User(name,lastName,nationalCode,username,password,age)
{}


Customer* Admin::createCustomer(LinkedList<User*>& users, QString name,QString lastName,
                                QString nationalCode, QString username,QString password, int age)
{
    User tempUser(name, lastName, nationalCode, username, password, age);

    if (users.findNode(&tempUser) != nullptr)
    {
        return nullptr;
    }
    Customer* newCustomer = new Customer(name, lastName, nationalCode, username, password, age);
    users.insertAtEnd(newCustomer);
    return newCustomer;
}


bool Admin::removeCustomer(LinkedList<User*> &users,QString username)
{
    User delUser("", "", "", username, "", 0);

    return users.deleteNode(&delUser);
}


bool Admin::editUser(LinkedList<User*> &users,User* userToChange,QString name, QString lastName,  QString nationalCode,
                         QString username, QString password, int age)
{
    if(userToChange ==nullptr){return false;}

    Node<User*>* current = users.getHead();
    while (current != nullptr)
    {
        if (current->data->getUsername() == username && current->data != userToChange)
        {
            return false;
        }
        current = current->next;
    }


    userToChange->setName(name);
    userToChange->setLastName(lastName);
    userToChange->setNationalCode(nationalCode);
    userToChange->setUsername(username);
    userToChange->setPassword(password);
    userToChange->setAge(age);
    return true;
}


void Admin::viewAllUsers(LinkedList<User*> &users)
{
    Node<User*> *current = users.getHead();
    while(current != nullptr)
    {
        //...
        current = current->next;
    }
}

void Admin::viewAllAccounts(LinkedList<User*> &users)
{

    Node<User*> *current = users.getHead();
    while(current != nullptr)
    {
        //...
        current = current->next;
    }

}

void Admin::viewAllAdmins(LinkedList<User*>& users)
{
    Node<User*>* current = users.getHead();
    while (current != nullptr)
    {
        Admin* admin = dynamic_cast<Admin*>(current->data);

        if (admin != nullptr)
        {
            //...
        }
        current = current->next;
    }
}

Account* Admin::addAccountToCustomer(Customer* customer, int accountType, double initialBalance)
{
    if (customer == nullptr) return nullptr;

    if (customer->getAccounts().size() >= 5) {
        qDebug() << "Error: Customer already has the maximum of 5 accounts.";
        return nullptr;
    }

    QString cardNumber = QString::number(QRandomGenerator::global()->bounded(1000000000000000, 9999999999999999));
    QString accountNumber = QString::number(QRandomGenerator::global()->bounded(10000000, 99999999));
    QString shabaNumber = "IR" + QString::number(QRandomGenerator::global()->bounded(1000000000, 9999999999));
    QString cvv2 = QString::number(QRandomGenerator::global()->bounded(100, 1000));
    QDate expDate = QDate::currentDate().addYears(4);
    QString pin = "1111";
    QString pin2 = "12345";

    Account* newAccount = nullptr;
    switch (accountType) {
    case 1:
        newAccount = new SavingAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    case 2:
        newAccount = new CurrentAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    case 3:
        newAccount = new CheckingAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    default:
        return nullptr;
    }

    customer->getAccounts().insertAtEnd(newAccount);
    return newAccount;
}
