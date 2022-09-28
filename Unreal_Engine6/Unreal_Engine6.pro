QT       += core gui openglwidgets
QT       += core gui testlib

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
    bulletsType\ball.cpp \
    utils\Vector3D.cpp \
    bulletsType\cannonball.cpp \
    bulletsType\fireball.cpp \
    scene1\gamegui.cpp \
    bulletsType\laser.cpp \
    main.cpp \
    mainwindow.cpp \
    utils\matrix.cpp \
    scene1\gun.cpp \
    scene1\Ground.cpp \
    utils\particles.cpp \
    tests\testVector.cpp \
    tests\testMatrix.cpp

HEADERS += \
    bulletsType\ball.h \
    utils\Vector3D.h \
    bulletsType\cannonball.h \
    bulletsType\fireball.h \
    scene1\gamegui.h \
    bulletsType\laser.h \
    mainwindow.h \
    utils\matrix.h \
    scene1\gun.h \
    scene1\Ground.h \
    utils\particles.h \
    tests\testVector.h \
    tests\testMatrix.h

RESOURCES += \
    ../res/textures.qrc

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
