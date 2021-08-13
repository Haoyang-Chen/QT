QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../../../Downloads/cscore.cpp \
    ../../../../../Downloads/csportman.cpp \
    ../../../../../Downloads/sportsmaninfotable.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../../../Downloads/cscore.h \
    ../../../../../Downloads/csportman.h \
    ../../../../../Downloads/sportsmaninfotable.h \
    dialog.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    demo_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
