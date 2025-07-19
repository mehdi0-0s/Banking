#include "customer.h"
#include "account.h"
Customer::Customer(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age)
    :User(name,lastName,nationalCode,username,password,age)
{
    this->dailyTransferTotal = 0.0;
    this->lastTransferDate = QDate::currentDate().addDays(-1);
}


LinkedList<Account*>& Customer::getAccounts()
{
     return this->accounts;
}


bool Customer::changeAccountPin(QString cardNumber,QString newPin)
{
    Node<Account*>* currentAccount = this->accounts.getHead();
    Account* foundAccount = nullptr;

    while (currentAccount != nullptr)
    {
        if (currentAccount->data->getCardNumber() == cardNumber)
        {
            foundAccount = currentAccount->data;
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (foundAccount != nullptr)
    {
        foundAccount->setPin(newPin);
        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::changeAccountPin2(QString cardNumber,QString newPin2)
{
    Node<Account*>* currentAccount = this->accounts.getHead();
    Account* foundAccount = nullptr;

    while (currentAccount != nullptr)
    {
        if (currentAccount->data->getCardNumber() == cardNumber)
        {
            foundAccount = currentAccount->data;
            break;
        }
        currentAccount = currentAccount->next;
    }

    if (foundAccount != nullptr)
    {
        foundAccount->setPin2(newPin2);
        return true;
    }
    else
    {
        return false;
    }
}

TransferResult Customer::cardTransfer(LinkedList<User*>& allUsers,QString sourceCardNumber,QString destCardNumber,
                            double amount,QString pin2,bool useDynamicPin)
{
    Node<Account*>* currentSource = this->accounts.getHead();
    Account* sourceAccount  = nullptr;

    while (currentSource != nullptr)
    {
        if (currentSource->data->getCardNumber() == sourceCardNumber)
        {
            sourceAccount  = currentSource->data;
            break;
        }
        currentSource = currentSource->next;
    }

    if (sourceAccount == nullptr)
    {
        return TransferResult::Error_SourceAccountNotFound;
    }


    Account* destAccount  = nullptr;
    Node<User*> * currentUser = allUsers.getHead();
    while(currentUser != nullptr && destAccount  == nullptr)
    {
        Customer* otherCustomer = dynamic_cast<Customer*>(currentUser->data);
        if (otherCustomer != nullptr)
        {
            Node<Account*>* currentDestNode = otherCustomer->getAccounts().getHead();
            while (currentDestNode != nullptr) {
                if (currentDestNode->data->getCardNumber() == destCardNumber) {
                    destAccount = currentDestNode->data;
                    break;
                }
                currentDestNode = currentDestNode->next;
            }
        }
        currentUser = currentUser->next;

    }

    if (destAccount == nullptr)
    {
        return TransferResult::Error_DestAccountNotFound;
    }


    if(sourceAccount->getExpirationDate() < QDate::currentDate())
    {
        return TransferResult::Error_CardExpired;
    }


    if(amount > 3000000)
    {
        return TransferResult::Error_TransactionLimitExceeded;
    }

    if (this->lastTransferDate != QDate::currentDate())
    {
        this->dailyTransferTotal = 0.0;
        this->lastTransferDate = QDate::currentDate();
    }
    if(this->dailyTransferTotal +amount > 6000000)
    {
        return TransferResult::Error_DailyLimitExceeded;
    }

    if(sourceAccount->getBalance() <amount)
    {
        return TransferResult::Error_InsufficientBalance;
    }

    if (amount <= 100000)
    {
        if (useDynamicPin || sourceAccount->getPin2() != pin2) {
            return TransferResult::Error_InvalidPin;
        }
    }
    else
    {
        if (!useDynamicPin || sourceAccount->getDynamicPin().isEmpty() || sourceAccount->getDynamicPin() != pin2) {
            return TransferResult::Error_InvalidPin;
        }

    }

    double fee = amount * 0.0001;

    if (sourceAccount->getBalance() < (amount + fee))
    {
        qDebug() << "Error: Insufficient balance to cover amount + fee.";
        return TransferResult::Error_InsufficientBalance;
    }

    sourceAccount->setBalance(sourceAccount->getBalance() - (amount + fee));
    destAccount->setBalance(destAccount->getBalance() + amount);

    this->dailyTransferTotal += amount;

    sourceAccount->setDynamicPin("");

    return TransferResult::Success;
}

