#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "account.h"

class SavingAccount :public Account
{
public:
    SavingAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                   QString cvv2, double balance,QDate expDate,QString pin,QString pin2);

    double calculateInterest(double interestRate = 0.1);
};

#endif // SAVINGACCOUNT_H
