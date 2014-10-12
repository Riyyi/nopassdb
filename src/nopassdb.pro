TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
LIBS += -L/usr/include/unistd.h -lcrypt
QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()
