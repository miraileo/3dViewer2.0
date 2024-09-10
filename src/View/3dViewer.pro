QT       += core gui opengl widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Model/OpenGL.cpp \
    ../Model/affine_transformations.cpp \
    ../Controller/buttonhandler.cpp \
    main.cpp \
    mainwindow.cpp \
    ../Model/obj_parser.cpp \

HEADERS += \
    ../Model/OpenGL.h \
    ../Model/affine_transformations.h \
    ../Controller/buttonhandler.h \
    mainwindow.h \
    ../Model/obj_parser.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
LIBS += -L/usr/local/lib -lGLU
