######################################################################
# Automatically generated by qmake (1.07a) Sat Apr 8 14:34:18 2006
######################################################################

TEMPLATE = app
CONFIG   = warn_on release console 
CONFIG  -= qt
#mac2017 QMAKE_LFLAGS += -static-libgcc
contains(QMAKE_CXX, g++) {
  !symbian:QMAKE_LFLAGS += -static-libgcc
}
INCLUDEPATH += ../lib

# Input
# HEADERS +=
SOURCES += rlhistory.cpp

!macx {
LIBS    += ../lib/librllib.so -lpthread
}
#macx::LIBS    += ../lib/librllib.dylib
macx::LIBS    += ../lib/librllib.a

TARGET = rlhistory
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

