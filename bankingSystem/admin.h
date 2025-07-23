#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "customer.h"

template<typename T>
class LinkedList;
class Account;

class Admin :public User
{
public:
    Admin(QString name, QString lastName,  QString nationalCode,
                QString username, QString password, int age);


    Customer* createCustomer(LinkedList<User*>& users, QString name,QString lastName,
                            QString nationalCode, QString username,QString password, int age);


    bool removeCustomer(LinkedList<User*> &users,QString username);

    bool editUser(LinkedList<User*> &users,User* user,QString name, QString lastName,  QString nationalCode,
                      QString username, QString password, int age);

    QList<QString> viewAllCustomers(LinkedList<User*> &users);

    QList<QString> viewAllAccounts(LinkedList<User*> &users);

    QList<QString> viewAllAdmins(LinkedList<User*>& users);

    Account* addAccountToCustomer(Customer* customer, int accountType, double initialBalance);
};

#endif // ADMIN_H
