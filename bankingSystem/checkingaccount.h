#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                    QString cvv2, double balance,QDate expDate,QString pin,QString pin2);

    bool grantLoan(double amount);

    QString getAccountType() override;
};

#endif // CHECKINGACCOUNT_H
