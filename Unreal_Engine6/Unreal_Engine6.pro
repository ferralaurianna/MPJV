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
    generators/Rigibody/inputforcegenerator.cpp \
    generators/Rigibody\forcegenerator.cpp \
    generators/geneinterface.cpp \
    generators/Rigibody\gravityforcegenerator.cpp \
    generators/gravitygenerator.cpp \
    generators/springfloatability.cpp \
    generators/Rigibody\springforcegenerator.cpp \
    generators/springtwoparticle.cpp \
    menu/windowmainmenu.cpp \
    scene2/Assets/Plateforme.cpp \
    scene2/Assets/asset.cpp \
    scene2/Assets/coin.cpp \
    scene2/Assets/spike.cpp \
    scene3/actorlist.cpp \
    scene3/gamegui3.cpp \
    utils/RigidBodySystem/Primitives/box.cpp \
    utils/RigidBodySystem/Primitives/plane.cpp \
    utils/RigidBodySystem/Primitives/primitives.cpp \
    utils/RigidBodySystem/Primitives/sphere.cpp \
    utils/RigidBodySystem/collisionregistreryrigidody.cpp \
    utils/RigidBodySystem/forceregistreryrigidbody.cpp \
    utils/RigidBodySystem/narrowphasedetector.cpp \
    utils/RigidBodySystem/physicsystem.cpp \
    utils\RigidBodySystem/actors.cpp \
    scene3/windowpart3.cpp \
    utils/ParticlesSystem\collisiondetector.cpp \
    utils/ParticlesSystem\collisionregistrery.cpp \
    scene2/gametimer2.cpp \
    scene2/windowgameover2.cpp \
    utils/ParticlesSystem\forceregistrery.cpp \
    utils/quaternion.cpp \
    utils/RigidBodySystem\rigidbody.cpp \
    utils\Vector3D.cpp \
    bulletsType\cannonball.cpp \
    bulletsType\fireball.cpp \
    scene1\gamegui.cpp \
    bulletsType\laser.cpp \
    main.cpp \
    utils\matrix.cpp \
    utils\ParticlesSystem\particlecontact.cpp \
    scene1\gun.cpp \
    scene1\ground.cpp \
    utils\ParticlesSystem\particles.cpp \
    tests\testVector.cpp \
    tests\testMatrix.cpp \
    scene2\blob.cpp \
    scene2\gamegui2.cpp \
    scene1\windowpart1.cpp \
    scene2\windowpart2.cpp

HEADERS += \
    bulletsType\ball.h \
    generators/Rigibody/inputforcegenerator.h \
    generators/Rigibody\forcegenerator.h \
    generators/geneinterface.h \
    generators/Rigibody\gravityforcegenerator.h \
    generators/gravitygenerator.h \
    generators/springflotability.h \
    generators/Rigibody\springforcegenerator.h \
    generators/springtwoparticle.h \
    menu/windowmainmenu.h \
    scene2/Assets/Plateforme.h \
    scene2/Assets/asset.h \
    scene2/Assets/coin.h \
    scene2/Assets/spike.h \
    scene3/actorlist.h \
    scene3/gamegui3.h \
    utils/RigidBodySystem/collisiondata.h \
    utils/RigidBodySystem/Primitives/box.h \
    utils/RigidBodySystem/Primitives/plane.h \
    utils/RigidBodySystem/Primitives/primitives.h \
    utils/RigidBodySystem/Primitives/sphere.h \
    utils/RigidBodySystem/collisionregistreryrigidody.h \
    utils/RigidBodySystem/forceregistreryrigidbody.h \
    utils/RigidBodySystem/narrowphasedetector.h \
    utils/RigidBodySystem/physicsystem.h \
    utils\RigidBodySystem\actors.h \
    scene3/windowpart3.h \
    utils/Polygon.h \
    utils/ParticlesSystem\collisiondetector.h \
    utils/ParticlesSystem\collisionregistrery.h \
    scene2/gametimer2.h \
    scene2/windowgameover2.h \
    utils/ParticlesSystem\forceregistrery.h \
    utils/quaternion.h \
    utils/RigidBodySystem\rigidbody.h \
    utils\Vector3D.h \
    bulletsType\cannonball.h \
    bulletsType\fireball.h \
    scene1\gamegui.h \
    bulletsType\laser.h \
    utils\matrix.h \
    utils\ParticlesSystem\particlecontact.h \
    scene1\gun.h \
    scene1\ground.h \
    utils\ParticlesSystem\particles.h \
    tests\testVector.h \
    tests\testMatrix.h \
    scene2\blob.h \
    scene2\gamegui2.h \
    scene1\windowpart1.h \
    scene2\windowpart2.h

RESOURCES += \
    ../res/textures.qrc

FORMS += \
    menu/windowmainmenu.ui \
    scene1\windowpart1.ui \
    scene2\windowgameover2.ui \
    scene2\windowpart2.ui \
    scene3/windowpart3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
