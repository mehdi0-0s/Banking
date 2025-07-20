#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class CustomerDashboard : public QMainWindow
{
    Q_OBJECT

public:
    CustomerDashboard(QWidget *parent = nullptr);
    ~CustomerDashboard();

private:
    Ui::MainWindow *ui;
};
#endif // CUSTOMERDASHBOARD_H
