QT       += core gui sql multimedia
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    ramassage.cpp \
    zone_verte.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    ramassage.h \
    zone_verte.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Ramassage_ar_TN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    buttons.qrc
