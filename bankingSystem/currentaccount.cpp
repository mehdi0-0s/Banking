#include "currentaccount.h"

CurrentAccount::CurrentAccount(QString cardNumber,QString accountNumber,QString shebaNumber,
                               QString cvv2, double balance,QDate expDate,QString pin,QString pin2)
                :Account(cardNumber, accountNumber, shebaNumber, cvv2, balance, expDate, pin, pin2)
{}

void CurrentAccount::generateMiniStatement()
{

}
