include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

HEADERS +=     \
    test_m.h

SOURCES +=     main.cpp  \
    ../app/m.c \
    ../app/save.c \
    ../app/cn.c \
    ../app/rch.c \
    ../app/shownumspaces.c \
    ../app/append_line.c \
    ../app/create_text.c \
    ../app/process_forward.c \
    ../app/remove_all.c \
    ../app/show.c \
    ../app/load.c

INCLUDEPATH += ../app

