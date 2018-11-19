# QT Features to be linked in
QT += core qml quick network

# This is an application
TEMPLATE = app

QMAKE_CXXFLAGS += -Werror

# Put intermediate files in the build directory
MOC_DIR     = build/moc
OBJECTS_DIR = build/obj

# Executable name
TARGET = ../franca-ara

HEADERS += imageprovider.h imagesource.h

# Compile these sources
SOURCES += main.cpp imageprovider.cpp imagesource.cpp

# Add generated code
HEADERS += src-gen/v1/genivi/aasr/showcase/*.hpp
SOURCES += src-gen/v1/genivi/aasr/showcase/*.cpp
INCLUDEPATH += src-gen

# Location of CommonAPI headers & libs (temporary, for local host
# development without SDK)
INCLUDEPATH += /usr/local/include/CommonAPI-3.1
LIBS += -L/usr/local/lib -lCommonAPI -lCommonAPI-SomeIP -lvsomeip

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Unix executable install path
target.path = $$PREFIX/usr/bin
INSTALLS += target

RESOURCES += qml.qrc resources.qrc
