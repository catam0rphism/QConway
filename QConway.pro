QT += core gui widgets

TEMPLATE = app
TARGET = QConway

QMAKE_CXXFLAGS += -std=c++1y

HEADERS += config.h

SOURCES += main.cpp \
	config.cpp
	