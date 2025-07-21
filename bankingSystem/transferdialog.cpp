#include "transferdialog.h"
#include "ui_transferdialog.h"
#include "customer.h"
transferDialog::transferDialog(LinkedList<User*>*allUsers,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transferDialog)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    connect(ui->withdraw_pushButton,&QPushButton::clicked,this,&QDialog::accept);
}

transferDialog::~transferDialog()
{
    delete ui;
}

void transferDialog::on_verify_pushButton_clicked()
{
    QString destCard = ui->destCard_lineEdit->text();
    QString recipientName = Customer::getRecipientName(*allUsers, destCard);
    ui->recipientNameLabel->setText(recipientName);

}

QString transferDialog::getSourceCard()  { return ui->sourceCard_lineEdit->text(); }
QString transferDialog::getDestCard()  { return ui->destCard_lineEdit->text(); }
double transferDialog::getAmount() { return ui->amount_lineEdit->text().toDouble(); }
QString transferDialog::getPin2()  { return ui->pin_lineEdit->text(); }
