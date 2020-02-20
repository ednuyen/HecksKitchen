QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bin.cpp \
    bread.cpp \
    bread_bin.cpp \
    cheese.cpp \
    cheese_bin.cpp \
    food.cpp \
    health.cpp \
    main.cpp \
    mainwindow.cpp \
    meat.cpp \
    meat_bin.cpp \
    player.cpp \
    secondwindow.cpp \
    target.cpp \
    veggie_bin.cpp \
    veggies.cpp \
    wall.cpp

HEADERS += \
    bin.h \
    bread.h \
    bread_bin.h \
    cheese.h \
    cheese_bin.h \
    food.h \
    health.h \
    mainwindow.h \
    meat.h \
    meat_bin.h \
    player.h \
    secondwindow.h \
    target.h \
    veggie_bin.h \
    veggies.h \
    wall.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures.qrc

DISTFILES += \
    ../Desktop/Welcome.png
