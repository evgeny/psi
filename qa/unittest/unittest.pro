CONFIG -= app_bundle

MOC_DIR = ../../src/.moc
OBJECTS_DIR = ../../src/.obj
UI_DIR = ../../src/.ui

CONFIG += pep
DEFINES += QT_STATICPLUGIN

include(../../conf.pri)
include(../../src/src.pri)
include(../../third-party/cppunit/cppunit.pri)

SOURCES += \
	unittest.cpp \
	unittestutil.cpp

include(../../src/capabilities/unittest/unittest.pri)
include(../../src/privacy/unittest/unittest.pri)
include(../../src/utilities/unittest/unittest.pri)
include(../../src/unittest/unittest.pri)

QMAKE_EXTRA_TARGETS = check
check.commands = \$(MAKE) && ./unittest

QMAKE_CLEAN += $(QMAKE_TARGET)
