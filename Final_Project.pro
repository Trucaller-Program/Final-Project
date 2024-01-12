QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chaining.cpp \
    hashtable.cpp \
    loginscene.cpp \
    main.cpp \
    mainwindow.cpp \
    searchingscene.cpp \
    searchnamescene.cpp \
    searchnumberscene.cpp

HEADERS += \
    chaining.h \
    hashtable.h \
    loginscene.h \
    mainwindow.h \
    searchingscene.h \
    searchnamescene.h \
    searchnumberscene.h

FORMS += \
    loginscene.ui \
    mainwindow.ui \
    searchingscene.ui \
    searchnamescene.ui \
    searchnumberscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
