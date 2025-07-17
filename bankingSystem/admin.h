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
};

#endif // ADMIN_H
