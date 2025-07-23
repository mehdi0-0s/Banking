#include "account.h"
#include<QRandomGenerator>
Account::Account(QString cardNumber,QString accountNumber,QString shebaNumber,
                 QString cvv2, double balance,QDate expDate,QString pin,  QString pin2)
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

QString Account::getPin2()
{
    return this->pin2;
}

QString Account::getDynamicPin()
{
    return dynamicPin;
}


QString Account::getAccountNumber(){
    return this->accountNumber;
}
QString Account::getShebaNumber(){
    return this->shebaNumber;
}
QString Account::getCvv2(){
    return this->cvv2;
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


QString Account::generateAndSetDynamicPin()
{
    int randomPin = QRandomGenerator::global()->bounded(100000, 1000000);
    this->dynamicPin = QString::number(randomPin);
    return this->dynamicPin;

}
