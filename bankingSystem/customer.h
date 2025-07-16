#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "LinkedList.h"

class Account;

class Customer :public User
{
private:
    LinkedList<Account *> accounts;
public:
    Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age);

};

#endif // CUSTOMER_H
