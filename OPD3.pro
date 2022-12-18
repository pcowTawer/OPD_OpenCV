QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    database.cpp \
    facerecognition.cpp \
    izmenenie.cpp \
    main.cpp \
    mainwindow.cpp \
    people.cpp \
    registrationnew.cpp \
    snimokcam.cpp \
    sqlite-amalgamation-3400000/shell.c \
    sqlite-amalgamation-3400000/sqlite3.c

HEADERS += \
    camera.h \
    database.h \
    facerecognition.h \
    izmenenie.h \
    mainwindow.h \
    people.h \
    registrationnew.h \
    snimokcam.h \
    sqlite-amalgamation-3400000/sqlite3.h \
    sqlite-amalgamation-3400000/sqlite3ext.h

FORMS += \
    camera.ui \
    izmenenie.ui \
    mainwindow.ui \
    people.ui \
    registrationnew.ui \
    snimokcam.ui

win32:RC_FILE = icon.rc

INCLUDEPATH += C:\lib\install\opencv\include

LIBS += -LC:\lib\install\opencv\x64\vc17\lib -lopencv_world460d -lopencv_img_hash460d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
