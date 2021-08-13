QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cscore.cpp \
    csportman.cpp \
    main.cpp \
    mainwindow.cpp \
    readonlydelegate.cpp \
    selectdialog.cpp \
    signupdialog.cpp \
    sportsmaninfotable.cpp

HEADERS += \
    cscore.h \
    csportman.h \
    mainwindow.h \
    readonlydelegate.h \
    selectdialog.h \
    signupdialog.h \
    sportsmaninfotable.h \
    ui_Signup.h \
    ui_mainwindow.h \
    ui_selectdialog.h \
    ui_signupdialog.h

FORMS += \
    Signup.ui \
    mainwindow.ui \
    selectdialog.ui \
    signupdialog.ui

TRANSLATIONS += \
    sport_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
