#-------------------------------------------------
#
# Project created by QtCreator 2019-05-08T16:33:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tourist
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindlg.cpp \
    newroutedlg.cpp \
    outputroutedlg.cpp \
    passbydlg.cpp \
    signupdlg.cpp \
    loginoptiondlg.cpp \
    printuserdlg.cpp \
    Time_Thread.cpp \
    Min_Cost.cpp \
    Min_Cost_Limited_Time.cpp \
    Min_Time.cpp \
    Prepare.cpp \
    Read_Trans_Table.cpp \
    Write_File.cpp \
    changeuserinfodlg.cpp \
    welcomedlg.cpp

HEADERS += \
        mainwindow.h \
    logindlg.h \
    newroutedlg.h \
    outputroutedlg.h \
    passbydlg.h \
    signupdlg.h \
    loginoptiondlg.h \
    printuserdlg.h \
    main.h \
    changeuserinfodlg.h \
    welcomedlg.h \
    time_thread.h

FORMS += \
        mainwindow.ui \
    logindlg.ui \
    newroutedlg.ui \
    outputroutedlg.ui \
    passbydlg.ui \
    signupdlg.ui \
    loginoptiondlg.ui \
    printuserdlg.ui \
    changeuserinfodlg.ui \
    welcomedlg.ui

DISTFILES +=

RESOURCES += \
    map.qrc
