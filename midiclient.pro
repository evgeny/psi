QT      +=  webkit
CONFIG  +=  uitools

linux-g++:	MCD = /home/vviro/peachnote/client
win32: 		MCD = "C:\workspace\music\online-piano\trunk\client"
macx:       MCD = /Users/yushen/peachnote-client

DEFINES += __WITH_PSI__

HEADERS +=	$$MCD/src/base/midiclient.h \
            $$MCD/src/base/mididevice.h \
            $$MCD/src/base/midistream.h             

SOURCES += 	\
		$$MCD/src/base/midiclient.cpp \
		$$MCD/src/base/midistorage.cpp \
		$$MCD/src/base/mididevice.cpp \
		$$MCD/src/base/midiqueue.cpp \
		$$MCD/src/base/midistream.cpp \
		$$MCD/src/base/utils.cpp \
		$$MCD/src/lib/rtmidi/RtMidi.cpp

win32 {
	DEFINES += __WINDOWS_MM__
	LIBS += -L$$MCD/lib/win
	LIBS += $$MCD/lib/win/boost_thread-mgw34-mt-1_37.dll $$MCD/lib/win/boost_filesystem-mgw34-mt-1_37.dll
	LIBS += $$MCD/lib/win/boost_system-mgw34-mt-1_37.dll $$MCD/lib/win/boost_date_time-mgw34-mt-1_37.dll
	LIBS += $$MCD/lib/win/sqlite3.dll $$MCD/lib/win/gloox.dll $$MCD/lib/win/log4cxx.dll
	LIBS += -lwinmm -lstdc++ -lm -lws2_32 -lSecur32 -lCrypt32 -lDnsapi
}

linux-g++ {
    DEFINES += __LINUX_ALSASEQ__
    LIBS += -L$$MCD/lib/linux64/shared
    LIBS += -lboost_thread -lboost_date_time -lboost_filesystem -lboost_system -lgloox -lsqlite3 -llog4cxx
    LIBS += -lgnutls -lssl -lcrypto -lz -lidn -lgpg-error -lasound -lrt -lpthread -lresolv -ldl
}

macx {
    DEFINES += __MACOSX_CORE__
    LIBS += -L$$MCD/lib/osx
    LIBS += -framework CoreMidi -framework CoreAudio -framework CoreFoundation
    LIBS += /Users/yushen/peachnote-client/lib/osx/liblog4cxx.dylib
    LIBS += /Users/yushen/peachnote-client/lib/osx/libboost_thread.a
    LIBS += /Users/yushen/peachnote-client/lib/osx/libboost_filesystem.a
    LIBS += /Users/yushen/peachnote-client/lib/osx/libboost_date_time.a
    LIBS += /Users/yushen/peachnote-client/lib/osx/libboost_system.a
    LIBS += /Users/yushen/peachnote-client/lib/osx/libgloox.a
    LIBS += /usr/lib/libsqlite3.dylib
	LIBS += 
	LIBRARY += -L/usr/local/lib
	LIBRARY += -L/usr/lib
	
}

INCLUDEPATH += $$MCD/include

