#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"
#include "addcustomerdialog.h"
#include "edituserdialog.h"
#include "customer.h"
#include "addaccountdialog.h"
#include <QMessageBox>
AdminDashboard::AdminDashboard(LinkedList<User*> *allUsers,Admin * logAdmin,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    this->logAdmin = logAdmin;

    this->updateCustomersDisplay();
    ui->admins_listWidget->addItems(this->logAdmin->viewAllAdmins(*this->allUsers));
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::updateCustomersDisplay()
{
    ui->customers_listWidget->clear();

    QList<QString> customersData = this->logAdmin->viewAllCustomers(*this->allUsers);
    ui->customers_listWidget->addItems(customersData);
    this->updateAllAccountsDisplay();
}

void AdminDashboard::on_addCustomer_pushButton_clicked()
{
    AddCustomerDialog addDialog(this);
    if (addDialog.exec() == QDialog::Accepted)
    {
        QString name = addDialog.getName();
        QString lastName = addDialog.getLastName();
        QString nationalCode = addDialog.getNationalCode();
        QString username = addDialog.getUsername();
        QString password = addDialog.getPassword();
        int age = addDialog.getAge();
        if (name.isEmpty() || lastName.isEmpty() || nationalCode.isEmpty() ||
            username.isEmpty() || password.isEmpty())
        {
            QMessageBox::warning(this, "خطای ورودی", "تمام فیلدها باید پر شوند.");
            return;
        }
        Customer* newCustomer = this->logAdmin->createCustomer(*this->allUsers, name, lastName,
                                                                    nationalCode, username, password, age);

        if (newCustomer != nullptr) {
            QMessageBox::information(this, "موفقیت", "مشتری جدید با موفقیت اضافه شد.");
            this->updateCustomersDisplay();
        } else {
            QMessageBox::warning(this, "خطا", "نام کاربری تکراری است یا خطای دیگری رخ داد.");
        }
    }

}


void AdminDashboard::on_deleteCustomer_pushButton_clicked()
{
    if(ui->customers_listWidget->selectedItems().empty()){
        QMessageBox::warning(this,"خطا" , "لطفا یک کاربر را برای حذف انتخاب کنید.");
        return;
    }

    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(this, "تأیید حذف", "آیا از حذف این مشتری اطمینان دارید؟ این عمل قابل بازگشت نیست.",
                                         QMessageBox::Yes | QMessageBox::No);

    if(confirmation == QMessageBox::Yes)
    {
        QString usernameToDelete = ui->customers_listWidget->currentItem()->text().split(" | ")[0].split(": ")[1];

        bool res = this->logAdmin->removeCustomer(*allUsers,usernameToDelete);
        if(res == true)
        {
            QMessageBox::information(this, "موفقیت", "مشتری با موفقیت حذف شد.");
            this->updateCustomersDisplay();
        }
        else
        {
            QMessageBox::critical(this, "خطا", "خطایی در حذف مشتری رخ داد.");
        }
    }

}


void AdminDashboard::on_editCustomer_pushButton_clicked()
{
    if(ui->customers_listWidget->selectedItems().empty()){
        QMessageBox::warning(this,"خطا" , "لطفا یک کاربر را برای ویرایش انتخاب کنید.");
        return;
    }
    QString usernameToEdit = ui->customers_listWidget->currentItem()->text().split(" | ")[0].split(": ")[1];
    User* userToEdit = findUserByUsername(usernameToEdit);

    if(userToEdit != nullptr)
    {

        editUserDialog editDialog(userToEdit,this);
        if(editDialog.exec() == QDialog::Accepted)
        {
            QString name = editDialog.getName();
            QString lastName = editDialog.getLastName();
            QString nationalCode = editDialog.getNationalCode();
            QString username = editDialog.getUsername();
            QString password = editDialog.getPassword();
            int age = editDialog.getAge();

            bool res = this->logAdmin->editUser(*allUsers,userToEdit,name,lastName,nationalCode,username,password,age);
            if(res == true)
            {
                QMessageBox::information(this, "موفقیت", "اطلاعات مشتری با موفقیت ویرایش شد.");
                this->updateCustomersDisplay();
            }
            else{
                QMessageBox::warning(this, "خطا", "نام کاربری جدید تکراری است.");
            }

        }
    }
    else
    {
        QMessageBox::critical(this, "خطا", "خطای داخلی: کاربر انتخاب شده در لیست داده‌ها یافت نشد.");
    }
}

void AdminDashboard::updateAllAccountsDisplay()
{
    ui->allAccounts_listWidget->clear();
    QList<QString> accountsData = this->logAdmin->viewAllAccounts(*this->allUsers);
    ui->allAccounts_listWidget->addItems(accountsData);

}


void AdminDashboard::on_addAccount_pushButton_clicked()
{
    if (ui->customers_listWidget->selectedItems().empty()) {
        QMessageBox::warning(this, "خطا", "لطفاً ابتدا مشتری مورد نظر را از لیست انتخاب کنید.");
        return;
    }

    QString username = ui->customers_listWidget->currentItem()->text().split(" | ")[0].split(": ")[1];
    User* user = findUserByUsername(username);
    Customer* targetCustomer = dynamic_cast<Customer*>(user);

    if (targetCustomer == nullptr)
    {
        QMessageBox::critical(this, "خطا", "کاربر انتخاب شده مشتری نیست یا یافت نشد.");
        return;
    }
    else
    {
        AddAccountDialog addAccountDialog(this);
        if(addAccountDialog.exec() == QDialog::Accepted)
        {
            int accountType = addAccountDialog.getAccountTypeIndex() + 1;
            double initialBalance = addAccountDialog.getBalance();

            Account* newAccount = this->logAdmin->addAccountToCustomer(targetCustomer,accountType,initialBalance);
            if (newAccount != nullptr) {
                QMessageBox::information(this, "موفقیت", "حساب جدید با موفقیت ایجاد شد.");
                this->updateCustomersDisplay();
            } else {
                QMessageBox::warning(this, "خطا", "ایجاد حساب ناموفق بود (احتمالاً سقف ۵ حساب پر شده است).");
            }
        }
    }

}

User* AdminDashboard::findUserByUsername(QString username)
{
    Node<User*>* current = this->allUsers->getHead();
    while(current != nullptr)
    {
        if(current->data->getUsername() == username) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}




void AdminDashboard::on_allAccounts_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString cardNumber = item->text().split(" | ")[2].split(": ")[1];

    Account* targetAccount = nullptr;
    Node<User*>* userNode = this->allUsers->getHead();
    while(userNode != nullptr && targetAccount == nullptr) {
        Customer* customer = dynamic_cast<Customer*>(userNode->data);
        if (customer) {
            Account* found = customer->findAccountByCardNumber(cardNumber);
            if (found) {
                targetAccount = found;
            }
        }
        userNode = userNode->next;
    }

    if (targetAccount) {
        QString details;
        details += "Card Number: " + targetAccount->getCardNumber() + "\n";
        details += "Account Number: " + targetAccount->getAccountNumber() + "\n";
        details += "Sheba Number: " + targetAccount->getShebaNumber() + "\n";
        details += "CVV2: " + targetAccount->getCvv2() + "\n";
        details += "Balance: " + QString::number(targetAccount->getBalance()) + "\n";
        details += "Expiration Date: " + targetAccount->getExpirationDate().toString("yyyy/MM") + "\n";
        details += "Account Type: " + targetAccount->getAccountType();

        QMessageBox::information(this, "Account Details", details);
    }
}


void AdminDashboard::on_editMyProfile_pushButton_clicked()
{
    editUserDialog editDialog(this->logAdmin, this);

    if (editDialog.exec() == QDialog::Accepted)
    {
        QString name = editDialog.getName();
        QString lastName = editDialog.getLastName();
        QString nationalCode = editDialog.getNationalCode();
        QString username = editDialog.getUsername();
        QString password = editDialog.getPassword();
        int age = editDialog.getAge();

        bool success = this->logAdmin->editUser(*this->allUsers, this->logAdmin,name,lastName,nationalCode,username,password,age);

        if (success) {
            QMessageBox::information(this, "موفقیت", "پروفایل شما با موفقیت به‌روز شد.");
            ui->admins_listWidget->clear();
            ui->admins_listWidget->addItems(this->logAdmin->viewAllAdmins(*this->allUsers));
        } else {
            QMessageBox::warning(this, "خطا", "نام کاربری جدید تکراری است.");
        }
    }
}

