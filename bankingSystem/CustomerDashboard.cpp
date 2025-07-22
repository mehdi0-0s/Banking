#include "CustomerDashboard.h"
#include "ui_CustomerDashboard.h"
#include "changepindialog.h"
#include "transferdialog.h"
#include <QMessageBox>
CustomerDashboard::CustomerDashboard(LinkedList<User*>*allUsers,Customer *logCustomer,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->logCustomer = logCustomer;
    this->allUsers = allUsers;

    this->updateAccountsDisplay();
}

CustomerDashboard::~CustomerDashboard()
{
    delete ui;
}

void CustomerDashboard::on_changePin_pushButton_clicked()
{
    if(ui->accounts_listWidget->selectedItems().empty())
    {
        QMessageBox::warning(this,"Error","Please select an account.");
        return;
    }
    ChangePinDialog changePinWindow(this);
    if(changePinWindow.exec() == QDialog::Accepted)
    {
        QString newPin = changePinWindow.getNewPin();

        if(newPin.isEmpty()){
            QMessageBox::warning(this,"Error","Please enter new pin.");
            return;
        }

        QString cardNumber =ui->accounts_listWidget->currentItem()->text().split(" | ")[0].split(": ")[1];
        bool res = logCustomer->changeAccountPin(cardNumber,newPin);

        if(res)
        {
            QMessageBox::information(this,"success","pin changed succesfully");
        }
        else
        {
            QMessageBox::warning(this,"Error","account ot found or  new pin was invalid");
        }
    }

}


void CustomerDashboard::updateAccountsDisplay()
{
    ui->accounts_listWidget->clear();

    Node<Account*>* current = this->logCustomer->getAccounts().getHead();
    while(current != nullptr)
    {
        QString accountInfo = QString("Card: %1 | Balance: %2")
        .arg(current->data->getCardNumber())
            .arg(current->data->getBalance());
        ui->accounts_listWidget->addItem(accountInfo);
        current = current->next;
    }
}


void CustomerDashboard::on_transfer_pushButton_clicked()
{
    transferDialog transferWindow(allUsers,logCustomer,this);
    if (transferWindow.exec() == QDialog::Accepted)
    {
        QString sourceCard = transferWindow.getSourceCard();
        QString destCard = transferWindow.getDestCard();
        double amount = transferWindow.getAmount();
        QString pin2 = transferWindow.getPin2();

        bool useDynamic = false;
        if (amount > 100000) {
            useDynamic = true;
        }

        TransferResult result = this->logCustomer->cardTransfer(*this->allUsers, sourceCard,destCard,
                                                                amount, pin2, useDynamic);

        switch (result) {
        case TransferResult::Success:
            QMessageBox::information(this, "موفقیت", "تراکنش با موفقیت انجام شد.");
            this->updateAccountsDisplay();
            break;
        case TransferResult::Error_SourceAccountNotFound:
            QMessageBox::warning(this, "خطا", "شماره کارت مبدأ در حساب‌های شما یافت نشد.");
            break;

        case TransferResult::Error_DestAccountNotFound:
            QMessageBox::warning(this, "خطا", "شماره کارت مقصد نامعتبر است.");
            break;

        case TransferResult::Error_CardExpired:
            QMessageBox::warning(this, "خطا", "کارت مبدأ منقضی شده است.");
            break;

        case TransferResult::Error_TransactionLimitExceeded:
            QMessageBox::warning(this, "خطا", "مبلغ تراکنش از سقف ۳,۰۰۰,۰۰۰ تومان بیشتر است.");
            break;

        case TransferResult::Error_DailyLimitExceeded:
            QMessageBox::warning(this, "خطا", "از سقف انتقال روزانه ۶,۰۰۰,۰۰۰ تومان عبور کرده‌اید.");
            break;

        case TransferResult::Error_InsufficientBalance:
            QMessageBox::warning(this, "خطا", "موجودی حساب کافی نیست.");
            break;

        case TransferResult::Error_InvalidPin:
            QMessageBox::warning(this, "خطا", "رمز دوم وارد شده نامعتبر است.");
            break;
        }
    }
}


void CustomerDashboard::on_logout_pushButton_clicked()
{
    this->close();
}

