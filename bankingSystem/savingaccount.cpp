#include "savingaccount.h"

SavingAccount::SavingAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                             QString cvv2, double balance,QDate expDate,QString pin,QString pin2)
                :Account(cardNumber, accountNumber, shebaNumber, cvv2, balance, expDate, pin, pin2)
{}

double SavingAccount::calculateInterest(double interestRate)
{
    return this->balance * interestRate;
}


QString SavingAccount::getAccountType(){
    return "Saving (سپرده)";
}
