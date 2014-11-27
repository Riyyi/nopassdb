TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    getoptpp/getopt_pp.cpp \
    arghelp.cpp \
    hash.cpp
LIBS += -L/usr/include/unistd.h -lcrypt
QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    getoptpp/getopt_pp.h \
    getoptpp/getopt_pp_standalone.h \
    headers.h \
    arghelp.h \
    hash.h
