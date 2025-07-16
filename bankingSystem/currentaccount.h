#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "account.h"


class CurrentAccount :public Account
{
public:
    CurrentAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                    QString cvv2, double balance,QDate expDate,QString pin,QString pin2);

     void generateMiniStatement();
};

#endif // CURRENTACCOUNT_H
