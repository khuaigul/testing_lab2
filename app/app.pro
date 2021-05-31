TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += \
    main.cpp \
    append_line.c \
    cn.c \
    create_text.c \
    load.c \
    m.c \
    process_forward.c \
    rch.c \
    remove_all.c \
    save.c \
    show.c \
    shownumspaces.c

HEADERS += \
    common.h \
    _text.h \
    text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror


