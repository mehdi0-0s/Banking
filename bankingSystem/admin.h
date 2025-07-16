#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

template<typename T>
class LinkedList;
class Customer;
class Account;

class Admin :public User
{
public:
    Admin(QString name, QString lastName,  QString nationalCode,
                QString username, QString password, int age);

};

#endif // ADMIN_H
