QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../scsc-swen/randnumgen.h \
    ../scsc-swen/basicstat.h \
    ../scsc-swen/nullhypothesis.h \
    ../scsc-swen/nullhypothesisparameter.h \
    ../scsc-swen/aprint.h \
    ../scsc-swen/swen.h \
    test-randnum-gen.h \
    test-basicstat.h \
    test-nullhypothesis.h
SOURCES += ../scsc-swen/randnumgen.cpp \
    ../scsc-swen/basicstat.cpp \
    ../scsc-swen/nullhypothesis.cpp \
    ../scsc-swen/nullhypothesisparameter.cpp \
    ../scsc-swen/aprint.cpp \
    main.cpp \
    test-randnum-gen.cpp \
    test-basicstat.cpp \
    test-nullhypothesis.cpp

INCLUDEPATH += ../scsc-swen

QMAKE_POST_LINK += ./${TARGET}
