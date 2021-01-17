QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libdivide_wrapper.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../LibDivide/LibDivide_global.h \
    ../LibDivide/libdivide.h \
    libdivide_wrapper.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-LibDivide-Desktop_Qt_5_12_10_MSVC2015_64bit-Debug/release/ -lLibDivide
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-LibDivide-Desktop_Qt_5_12_10_MSVC2015_64bit-Debug/debug/ -lLibDivide

#INCLUDEPATH += $$PWD/../build-LibDivide-Desktop_Qt_5_12_10_MSVC2015_64bit-Debug/debug
#DEPENDPATH += $$PWD/../build-LibDivide-Desktop_Qt_5_12_10_MSVC2015_64bit-Debug/debug

#LIBS += "C:\Qt\build-LibDivide-Desktop_Qt_5_12_10_MSVC2015_64bit-Debug\debug\libdivide.lib"

INCLUDEPATH += ../LibDivide
DEPENDPATH += ../LibDivide
LIBS += -L../build-LibDivide-Desktop_Qt_5_12_10_MSVC2017_32bit-Debug/debug -llibDivide
