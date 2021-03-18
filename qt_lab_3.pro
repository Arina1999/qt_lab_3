QT += core gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
    FileStrategy.cpp \
    FolderStrategy.cpp \
        main.cpp \

HEADERS += \ \
    AbstractStrategy.h \
    FileStrategy.h \
    FolderStrategy.h

DEFINES += DIR=\\\"$$PWD\\\"
