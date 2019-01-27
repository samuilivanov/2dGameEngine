TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
    sandboxApp.cpp

unix:!macx: LIBS += -L$$PWD/../build-supreme-fiesta-game-engine-Desktop_Qt_5_12_0_GCC_64bit-Debug/ -lsupreme-fiesta-game-engine

INCLUDEPATH += $$PWD/../build-supreme-fiesta-game-engine-Desktop_Qt_5_12_0_GCC_64bit-Debug
INCLUDEPATH += /home/samuil/dev/SFGE/supreme-fiesta-game-engine/
DEPENDPATH += $$PWD/../build-supreme-fiesta-game-engine-Desktop_Qt_5_12_0_GCC_64bit-Debug
