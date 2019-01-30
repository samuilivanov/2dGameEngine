#-------------------------------------------------
#
# Project created by QtCreator 2019-01-27T13:36:44
#
#-------------------------------------------------

QT       -= gui
QT       += core

TARGET = supreme-fiesta-game-engine
TEMPLATE = lib

DEFINES += SUPREMEFIESTAGAMEENGINE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/application.cpp \
    sfgepch.cpp \
    src/Utils/texturemanager.cpp \
    src/map.cpp \
    src/vector2d.cpp \
    src/Platform/Linux/linuxwindow.cpp \
    src/Utils/log.cpp

HEADERS += \
    src/application.h \
    src/core.h \
    sfge.h \
    sfgepch.h \
    src/entrypoint.h \
    src/Utils/texturemanager.h \
    src/map.h \
    src/ECS/collidercomponent.h \
    src/ECS/components.h \
    src/ECS/ecs.h \
    src/ECS/keyboardcontroller.h \
    src/ECS/spritecomponent.h \
    src/ECS/transformcomponent.h \
    src/vector2d.h \
    src/Platform/Linux/linuxwindow.h \
    src/window.h \
    src/Utils/log.h

LIBS += -lSDL2 -lSDL2_image

unix {
    target.path = /usr/lib
    INSTALLS += target
}
