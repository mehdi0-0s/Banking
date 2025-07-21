#ifndef CHANGEPINDIALOG_H
#define CHANGEPINDIALOG_H

#include <QDialog>

namespace Ui {
class ChangePinDialog;
}

class ChangePinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePinDialog(QWidget *parent = nullptr);
    ~ChangePinDialog();
    QString getNewPin();

private:
    Ui::ChangePinDialog *ui;
};

#endif // CHANGEPINDIALOG_H
