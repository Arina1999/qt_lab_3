QT += core gui widgets charts

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
    CustomFileModel.cpp \
    FileStrategy.cpp \
    FolderStrategy.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AbstractStrategy.h \
    StatsUpdater.h \
    CustomFileModel.h \
    FileStrategy.h \
    FolderStrategy.h \
    mainwindow.h

#DEFINES += DIR=\\\"$$PWD\\\"

FORMS += \
    mainwindow.ui
