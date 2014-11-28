QMAKE_MAC_SDK = macosx10.9
CONFIG   += x86_64
QT   += core gui widgets multimedia

HEADERS += \
    personnage.h \
    scene.h \
    zelda.h \
    controller.h \
    niveaux.h \
    model.h \
    map.h \
    ennemis.h \
    monture.h \
    sword.h \
    weapon.h \
    quete.h \
    item.h

SOURCES += \
    main.cpp \
    personnage.cpp \
    scene.cpp \
    zelda.cpp \
    controller.cpp \
    niveaux.cpp \
    model.cpp \
    map.cpp \
    ennemis.cpp \
    monture.cpp \
    sword.cpp \
    weapon.cpp \
    quete.cpp \
    item.cpp

RESOURCES += \
    ressources.qrc
