#include "admin.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "CheckingAccount.h"
#include "QRandomGenerator"
Admin::Admin(QString name, QString lastName,  QString nationalCode,QString username, QString password, int age)
        :User(name,lastName,nationalCode,username,password,age)
{}


Customer* Admin::createCustomer(LinkedList<User*>& users, QString name,QString lastName,
                                QString nationalCode, QString username,QString password, int age)
{
    User tempUser(name, lastName, nationalCode, username, password, age);

    if (users.findNode(&tempUser) != nullptr)
    {
        return nullptr;
    }
    Customer* newCustomer = new Customer(name, lastName, nationalCode, username, password, age);
    users.insertAtEnd(newCustomer);
    return newCustomer;
}


bool Admin::removeCustomer(LinkedList<User*> &users,QString username)
{
    User delUser("", "", "", username, "", 0);

    return users.deleteNode(&delUser);
}


bool Admin::editUser(LinkedList<User*> &users,User* userToChange,QString name, QString lastName,  QString nationalCode,
                         QString username, QString password, int age)
{
    if(userToChange ==nullptr){return false;}

    Node<User*>* current = users.getHead();
    while (current != nullptr)
    {
        if (current->data->getUsername() == username && current->data != userToChange)
        {
            return false;
        }
        current = current->next;
    }


    userToChange->setName(name);
    userToChange->setLastName(lastName);
    userToChange->setNationalCode(nationalCode);
    userToChange->setUsername(username);
    userToChange->setPassword(password);
    userToChange->setAge(age);
    return true;
}


QList<QString> Admin::viewAllCustomers(LinkedList<User*> &users)
{
    QList<QString> customerDisplayList;
    Node<User*>* current = users.getHead();
    while (current != nullptr) {
        Customer* customer = dynamic_cast<Customer*>(current->data);
        if (customer) {
            QString info = QString("Username: %1 | Name: %2 %3 | National Code:%4 | Age: %5 | Number of accounts: %6")
                            .arg(customer->getUsername() , customer->getName() , customer->getLastName()
                                    ,customer->getNationalCode(),QString::number(customer->getAge())
                                    ,QString::number(customer->getAccounts().size()));
            customerDisplayList.append(info);
        }
        current = current->next;
    }
    return customerDisplayList;
}

QList<QString> Admin::viewAllAccounts(LinkedList<User*> &users)
{
    QList<QString> accountDisplayList;
    Node<User*>* currentUserNode = users.getHead();

    while (currentUserNode != nullptr)
    {
        Customer* customer = dynamic_cast<Customer*>(currentUserNode->data);
        if (customer)
        {
            LinkedList<Account*>& accounts = customer->getAccounts();
            Node<Account*>* currentAccountNode = accounts.getHead();
            while (currentAccountNode != nullptr)
            {
                QString accountInfo = QString("Owner: %1 | Type: %2 | Card: %3 | Balance: %4 | Exp: %5")
                    .arg(customer->getUsername())
                    .arg(currentAccountNode->data->getAccountType())
                    .arg(currentAccountNode->data->getCardNumber())
                    .arg(currentAccountNode->data->getBalance())
                    .arg(currentAccountNode->data->getExpirationDate().toString("yyyy/MM"));
                accountDisplayList.append(accountInfo);
                currentAccountNode = currentAccountNode->next;
            }
        }
        currentUserNode = currentUserNode->next;
    }
    return accountDisplayList;

}

QList<QString> Admin::viewAllAdmins(LinkedList<User*>& users)
{
    QList<QString> adminDisplayList;
    Node<User*>* current = users.getHead();
    while (current != nullptr)
    {
        Admin* admin = dynamic_cast<Admin*>(current->data);
        if (admin) {
            QString adminInfo = QString("Username: %1 | Name: %2 %3 | National Code: %4 | Age: %5")
                    .arg(admin->getUsername(), admin->getName(), admin->getLastName() ,
                                admin->getNationalCode(),QString::number(admin->getAge()));
            adminDisplayList.append(adminInfo);
        }
        current = current->next;
    }
    return adminDisplayList;
}

Account* Admin::addAccountToCustomer(Customer* customer, int accountType, double initialBalance)
{
    if (customer == nullptr) return nullptr;

    if (customer->getAccounts().size() >= 5) {
        qDebug() << "Error: Customer already has the maximum of 5 accounts.";
        return nullptr;
    }

    QString cardNumber = QString::number(QRandomGenerator::global()->bounded(1000000000000000, 9999999999999999));
    QString accountNumber = QString::number(QRandomGenerator::global()->bounded(10000000, 99999999));
    QString shabaNumber = "IR" + QString::number(QRandomGenerator::global()->bounded(1000000000, 9999999999));
    QString cvv2 = QString::number(QRandomGenerator::global()->bounded(100, 1000));
    QDate expDate = QDate::currentDate().addYears(4);
    QString pin = "1111";
    QString pin2 = QString::number(QRandomGenerator::global()->bounded(10000, 99999));

    Account* newAccount = nullptr;
    switch (accountType) {
    case 1:
        newAccount = new SavingAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    case 2:
        newAccount = new CurrentAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    case 3:
        newAccount = new CheckingAccount(cardNumber, accountNumber, shabaNumber, cvv2, initialBalance, expDate, pin, pin2);
        break;
    default:
        return nullptr;
    }

    customer->getAccounts().insertAtEnd(newAccount);
    return newAccount;
}
