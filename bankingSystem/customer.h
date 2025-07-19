#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "LinkedList.h"
#include "account.h"

class Customer :public User
{
private:
    LinkedList<Account *> accounts;
public:
    Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age);
    LinkedList<Account*>& getAccounts();

    bool changeAccountPin(QString cardNumber,QString newPin);

    bool changeAccountPin2(QString cardNumber,QString newPin2);

};

#endif // CUSTOMER_H
