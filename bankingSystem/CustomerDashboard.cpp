#include "CustomerDashboard.h"
#include "ui_CustomerDashboard.h"

CustomerDashboard::CustomerDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

CustomerDashboard::~CustomerDashboard()
{
    delete ui;
}
