#-------------------------------------------------
#
# Project created by QtCreator 2018-04-15T16:33:37
#
#-------------------------------------------------

QT       += core gui network
QT       += multimedia multimediawidgets
CONFIG   += resources_big
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Toolkit
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
    src/main.cpp \
    src/mainmenu.cpp \
    src/calculator.cpp \
    src/assistant.cpp \
    src/lottery.cpp \
    src/meme.cpp

HEADERS += \
    src/mainmenu.h \
    src/calculator.h \
    src/assistant.h \
    src/meme.h \
    src/lottery.h

FORMS += \
    src/mainmenu.ui \
    src/calculator.ui \
    src/assistant.ui \
    src/lottery.ui \
    src/meme.ui

RESOURCES += \
    resources.qrc
