QT       += core gui openglwidgets
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    Vector3D.cpp \
    cannonball.cpp \
    gamegui.cpp \
    laser.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    particules.cpp

HEADERS += \
    ball.h \
    Vector3D.h \
    cannonball.h \
    gamegui.h \
    laser.h \
    mainwindow.h \
    matrix.h \
    particules.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
