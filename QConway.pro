QT += core gui widgets

TEMPLATE = app
TARGET = QConway

QMAKE_CXXFLAGS += -std=c++1y

HEADERS += config.h \
	life.h

SOURCES += main.cpp \
	config.cpp \
	life.cpp
	