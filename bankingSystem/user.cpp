#include "user.h"
#include "LinkedList.h"

User::User(QString name, QString lastName, QString nationalCode, QString username, QString password, int age)
    : name(name), lastName(lastName), nationalCode(nationalCode), username(username), password(password), age(age)
{}

QString User::getName() { return this->name; }
QString User::getLastName() { return this->lastName; }
QString User::getNationalCode() { return this->nationalCode; }
QString User::getUsername() { return this->username; }
QString User::getPassword() { return this->password; }
int User::getAge() { return this->age; }

void User::setName(QString newName) { this->name = newName; }
void User::setLastName(QString newLastName) { this->lastName = newLastName; }
void User::setAge(int newAge) { this->age = newAge; }
void User::setPassword(QString newPassword) { this->password = newPassword; }
void User::setNationalCode(QString newNationalCode) { this->nationalCode = newNationalCode; }
void User::setUsername(QString newUsername) { this->username = newUsername; }

bool User::operator==(const User& other) const
{
    return this->username == other.username;
}

bool User::operator!=(const User& other) const
{
    return !(*this == other);
}

User* User::signUp(LinkedList<User*>& usersList, QString name, QString lastName,
                  QString nationalCode, QString username, QString password, int age)
{

    Node <User*> *current = usersList.getHead();
    while(current != nullptr)
    {
        if(current->data->getUsername() == username )
        {
            return nullptr;
        }
        current = current->next;
    }

    User* newUser = new User(name, lastName, nationalCode, username, password, age);
    usersList.insertAtEnd(newUser);
    return newUser;
}

User* User::logIn(LinkedList<User*>& usersList, const QString& username, const QString& password)
{
    Node <User*> *current = usersList.getHead();
    while(current != nullptr)
    {
        if(current->data->getUsername() == username )
        {
            if(current->data->getPassword() == password)
            {
                return current->data;
            }
            return nullptr;
        }
        current = current->next;
    }
    return nullptr;
}

