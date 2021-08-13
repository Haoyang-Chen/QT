QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogadd.cpp \
    dialogerror.cpp \
    dialogfind.cpp \
    dialogsal.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    manage.cpp \
    readonlydelegate.cpp \
    salary.cpp

HEADERS += \
    Employee.h \
    dialogadd.h \
    dialogerror.h \
    dialogfind.h \
    dialogsal.h \
    employee.h \
    employee.h \
    mainwindow.h \
    manage.h \
    readonlydelegate.h \
    salary.h

FORMS += \
    dialogadd.ui \
    dialogerror.ui \
    dialogfind.ui \
    dialogsal.ui \
    mainwindow.ui

TRANSLATIONS += \
    Employee_Salary_Management_sys_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data
