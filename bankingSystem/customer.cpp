#include "customer.h"

Customer::Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age)
    :User(name,lastName,nationalCode,username,password,age)
{}


 LinkedList<Account*>& Customer::getAccounts()
{
     return this->accounts;
}
