#ifndef USER_H
#define USER_H

#include <QString>

template<typename T>
class LinkedList;

class User
{
protected:
    QString name;
    QString lastName;
    QString nationalCode;
    QString username;
    QString password;
    int age;

public:
    User(QString name, QString lastName, QString nationalCode, QString username, QString password, int age);

    QString getName() ;
    QString getLastName() ;
    QString getNationalCode() ;
    QString getUsername() ;
    QString getPassword() ;
    int getAge();

    void setName(QString newName);
    void setLastName(QString newLastName);
    void setNationalCode(QString newNationalCode);
    void setUsername(QString newUserName);
    void setAge(int newAge);
    void setPassword(QString newPassword);

    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;

    static User* signUp(LinkedList<User*>& usersList, QString name,  QString lastName,
                        QString nationalCode,  QString username,QString password, int age);

    static User* logIn(LinkedList<User*>& usersList, const QString& username, const QString& password);

    virtual ~User();
};

#endif // USER_H
