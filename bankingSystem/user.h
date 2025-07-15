#ifndef USER_H
#define USER_H

#include <QString>

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
    void setNationalCode();
    void setUsername();
    void setAge(int newAge);
    void setPassword(QString newPassword);
};

#endif // USER_H
