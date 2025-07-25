QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminDashboard.cpp \
    CustomerDashboard.cpp \
    account.cpp \
    addaccountdialog.cpp \
    addcustomerdialog.cpp \
    admin.cpp \
    changepindialog.cpp \
    checkingaccount.cpp \
    currentaccount.cpp \
    customer.cpp \
    edituserdialog.cpp \
    logindialog.cpp \
    main.cpp \
    savingaccount.cpp \
    transferdialog.cpp \
    user.cpp

HEADERS += \
    AdminDashboard.h \
    CustomerDashboard.h \
    LinkedList.h \
    Node.h \
    account.h \
    addaccountdialog.h \
    addcustomerdialog.h \
    admin.h \
    changepindialog.h \
    checkingaccount.h \
    currentaccount.h \
    customer.h \
    edituserdialog.h \
    logindialog.h \
    savingaccount.h \
    transferdialog.h \
    user.h

FORMS += \
    AdminDashboard.ui \
    CustomerDashboard.ui \
    addaccountdialog.ui \
    addcustomerdialog.ui \
    changepindialog.ui \
    edituserdialog.ui \
    logindialog.ui \
    transferdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
