#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDate>

class Account
{
private:
    QString cardNumber;
    QString accountNumber;
    QString shebaNumber;
    QString cvv2;
    double balance;
    QDate expirationDate;
    QString pin;
    QString pin2;
    QString dynamicPin;
public:
    Account(QString cardNumber,QString accountNumber,QString shebaNumber,
                QString cvv2, double balance,QDate expDate,QString &pin,  QString pin2);

    QString getCardNumber();
    double getBalance();
    QDate getExpirationDate();

    void setBalance(double newBalance);
    void setPin(QString newPin);
    void setPin2(QString newPin2);
    void setDynamicPin(QString newDynamicPin);

    bool operator==(const Account& other) const;
};

#endif // ACCOUNT_H
