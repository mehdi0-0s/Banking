#include "changepindialog.h"
#include "ui_changepindialog.h"
#include <QIntValidator>
ChangePinDialog::ChangePinDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePinDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{0,4}"), this));
    connect(ui->pushButton,&QPushButton::clicked,this,&QDialog::accept);
}

ChangePinDialog::~ChangePinDialog()
{
    delete ui;
}


QString ChangePinDialog::getNewPin()
{
    return ui->lineEdit->text();
}
