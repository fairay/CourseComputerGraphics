#-------------------------------------------------
#
# Project created by QtCreator 2020-07-09T17:16:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = course_CG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    3d_prmitives/point.cpp \
    3d_prmitives/vector.cpp \
    3d_prmitives/polygon.cpp \
    errors/base_error.cpp \
    3d_prmitives/model.cpp \
    3d_prmitives/ball_model.cpp \
    3d_prmitives/box_model.cpp \
    errors/objects.cpp \
    errors/primitives.cpp \
    objects/scene_object.cpp \
    objects/simple_object.cpp \
    objects/leg.cpp \
    objects/camera.cpp \
    objects/light_source.cpp

HEADERS += \
        mainwindow.h \
    3d_prmitives/model.h \
    3d_prmitives/point.h \
    3d_prmitives/vector.h \
    3d_prmitives/polygon.h \
    errors/base_error.h \
    3d_prmitives/vertex.h \
    3d_prmitives/ball_model.h \
    3d_prmitives/box_model.h \
    commands/test.h \
    managers/test.h \
    scene/scene.h \
    scene/interface.h \
    objects/scene_object.h \
    errors/primitives.h \
    errors/objects.h \
    objects/simple_object.h \
    objects/leg.h \
    objects/camera.h \
    objects/light_source.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
