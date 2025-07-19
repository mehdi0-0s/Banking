#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<QDate>

#include "user.h"
#include "LinkedList.h"
#include "account.h"


enum class TransferResult {
    Success,
    Error_SourceAccountNotFound,
    Error_DestAccountNotFound,
    Error_CardExpired,
    Error_TransactionLimitExceeded,
    Error_DailyLimitExceeded,
    Error_InsufficientBalance,
    Error_InvalidPin
};



class Customer :public User
{
private:
    LinkedList<Account *> accounts;
    double dailyTransferTotal;
    QDate lastTransferDate;
public:
    Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age);
    LinkedList<Account*>& getAccounts();

    bool changeAccountPin(QString cardNumber,QString newPin);

    bool changeAccountPin2(QString cardNumber,QString newPin2);


    TransferResult cardTransfer(LinkedList<User*>& allUsers,QString sourceCardNumber,QString destCardNumber,double amount,QString pin2,bool useDynamicPin);

};

#endif // CUSTOMER_H
