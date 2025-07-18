#include "admin.h"

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
