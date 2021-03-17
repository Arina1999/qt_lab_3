QT += core gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
    FileStrategy.cpp \
    FolderStrategy.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AbstractStrategy.h \
    FileStrategy.h \
    FolderStrategy.h \
    mainwindow.h

#DEFINES += DIR=\\\"$$PWD\\\"

FORMS += \
    mainwindow.ui
