#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"
#include "addcustomerdialog.h"
#include "edituserdialog.h"
#include <QMessageBox>
AdminDashboard::AdminDashboard(LinkedList<User*> *allUsers,Admin * logAdmin,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    this->allUsers = allUsers;
    this->logAdmin = logAdmin;

    this->updateCustomersDisplay();
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::updateCustomersDisplay()
{
    ui->customers_listWidget->clear();

    Node<User*>* current = this->allUsers->getHead();
    while (current != nullptr)
    {
        Customer* customer = dynamic_cast<Customer*>(current->data);
        if (customer)
        {
            QString customerInfo = QString("Username: %1 | Name: %2")
            .arg(customer->getUsername())
            .arg(customer->getName() + " " + customer->getLastName());
            ui->customers_listWidget->addItem(customerInfo);
        }
        current = current->next;
    }
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
    User tempUserToSearch("", "", "", usernameToEdit, "", 0);
    Node<User*>* foundNode = this->allUsers->findNode(&tempUserToSearch);

    if(foundNode != nullptr)
    {
        User* userToEdit = foundNode->data;
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

