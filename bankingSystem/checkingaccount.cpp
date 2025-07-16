#include "checkingaccount.h"

CheckingAccount::CheckingAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                                 QString cvv2, double balance,QDate expDate,QString pin,QString pin2)
                :Account(cardNumber, accountNumber, shebaNumber, cvv2, balance, expDate, pin, pin2)
{}

bool CheckingAccount::grantLoan(double amount)
{
    if (amount > 0)
    {
        this->balance += amount;
        return true;
    }
    return false;
}
