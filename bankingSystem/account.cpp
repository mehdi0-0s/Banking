#include "account.h"

Account::Account(QString cardNumber,QString accountNumber,QString shebaNumber,
                 QString cvv2, double balance,QDate expDate,QString &pin,  QString pin2)
        :cardNumber(cardNumber), accountNumber(accountNumber), shebaNumber(shebaNumber),
    cvv2(cvv2), balance(balance), expirationDate(expDate), pin(pin), pin2(pin2)
{
    dynamicPin ="";
}

QString Account::getCardNumber()
{
    return cardNumber;
}

double Account::getBalance()
{
    return balance;
}

QDate Account::getExpirationDate()
{
    return expirationDate;
}

void Account::setBalance(double newBalance)
{
    balance = newBalance;
}

void Account::setPin(QString newPin)
{
    pin = newPin;
}

void Account::setPin2(QString newPin2)
{
    pin2 = newPin2;
}

void Account::setDynamicPin(QString newDynamicPin)
{
    dynamicPin = newDynamicPin;
}

bool Account::operator==(const Account& other) const
{
    return this->cardNumber == other.cardNumber;
}
