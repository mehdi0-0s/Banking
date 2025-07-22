#include "transferdialog.h"
#include "ui_transferdialog.h"
#include "customer.h"
#include <QMessageBox>
transferDialog::transferDialog(LinkedList<User*>*allUsers,Customer *customer,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transferDialog)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    logCustomer = customer;
    connect(ui->transfer_pushButton,&QPushButton::clicked,this,&QDialog::accept);
    ui->dynamicPin_pushButton->setEnabled(false);
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

void transferDialog::on_amount_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.toDouble() > 100000)
    {
        ui->dynamicPin_pushButton->setEnabled(true);
    }
    else{
        ui->dynamicPin_pushButton->setEnabled(false);
    }
}


void transferDialog::on_dynamicPin_pushButton_clicked()
{
    QString sourceCard = ui->sourceCard_lineEdit->text();
    if (sourceCard.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً ابتدا شماره کارت مبدأ را وارد کنید.");
        return;
    }


    Account* sourceAccount = this->logCustomer->findAccountByCardNumber(sourceCard);

    if (sourceAccount) {
        QString dynamicPin = sourceAccount->generateAndSetDynamicPin();

        QMessageBox::information(this, "رمز پویا", "رمز پویای شما: " + dynamicPin + "\nاین رمز یکبار مصرف است و فقط برای این تراکنش معتبر است.");
    } else {
        QMessageBox::warning(this, "خطا", "شماره کارت مبدأ یافت نشد.");
    }
}

