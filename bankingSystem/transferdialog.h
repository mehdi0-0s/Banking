#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>
#include"user.h"
#include"LinkedList.h"
namespace Ui {
class transferDialog;
}

class transferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transferDialog(LinkedList<User*>*allUsers,QWidget *parent = nullptr);
    ~transferDialog();
    QString getSourceCard() ;
    QString getDestCard() ;
    double getAmount() ;
    QString getPin2() ;
private slots:
    void on_verify_pushButton_clicked();



private:
    Ui::transferDialog *ui;
    LinkedList<User*>*allUsers;
};

#endif // TRANSFERDIALOG_H
