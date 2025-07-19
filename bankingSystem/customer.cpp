#include "customer.h"
#include "account.h"

Customer::Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age)
    :User(name,lastName,nationalCode,username,password,age)
{}


 LinkedList<Account*>& Customer::getAccounts()
{
     return this->accounts;
}


bool Customer::changeAccountPin(QString cardNumber,QString newPin)
{
    Node<Account*>* currentAccount = this->accounts.getHead();
    Account* foundAccount = nullptr;

    while (currentAccount != nullptr)
    {
        if (currentAccount->data->getCardNumber() == cardNumber)
        {
            foundAccount = currentAccount->data;
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (foundAccount != nullptr)
    {
        foundAccount->setPin(newPin);
        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::changeAccountPin2(QString cardNumber,QString newPin2)
{
    Node<Account*>* currentAccount = this->accounts.getHead();
    Account* foundAccount = nullptr;

    while (currentAccount != nullptr)
    {
        if (currentAccount->data->getCardNumber() == cardNumber)
        {
            foundAccount = currentAccount->data;
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (foundAccount != nullptr)
    {
        foundAccount->setPin2(newPin2);
        return true;
    }
    else
    {
        return false;
    }
}
