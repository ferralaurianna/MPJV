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
    generators/geneinterface.cpp \
    generators/gravitygenerator.cpp \
    generators/springtwoparticle.cpp \
    utils/forceregistrery.cpp \
    utils\Vector3D.cpp \
    bulletsType\cannonball.cpp \
    bulletsType\fireball.cpp \
    scene1\gamegui.cpp \
    bulletsType\laser.cpp \
    main.cpp \
    utils\matrix.cpp \
    scene1\gun.cpp \
    scene1\ground.cpp \
    utils\particles.cpp \
    tests\testVector.cpp \
    tests\testMatrix.cpp \
    scene1\windowpart1.cpp \
    scene2\windowpart2.cpp

HEADERS += \
    bulletsType\ball.h \
    generators/geneinterface.h \
    generators/gravitygenerator.h \
    generators/springtwoparticle.h \
    utils/forceregistrery.h \
    utils\Vector3D.h \
    bulletsType\cannonball.h \
    bulletsType\fireball.h \
    scene1\gamegui.h \
    bulletsType\laser.h \
    utils\matrix.h \
    scene1\gun.h \
    scene1\ground.h \
    utils\particles.h \
    tests\testVector.h \
    tests\testMatrix.h \
    scene1\windowpart1.h \
    scene2\windowpart2.h

RESOURCES += \
    ../res/textures.qrc

FORMS += \
    scene1\windowpart1.ui \
    scene2\windowpart2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
