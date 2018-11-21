TEMPLATE = app
CONFIG += ordered
CONFIG += c++11 warn_on

# QT Features to be linked in
QT += core qml quick network

QMAKE_CXXFLAGS += -Werror

# Put intermediate files in the build directory
MOC_DIR     = build/moc
OBJECTS_DIR = build/obj

# Executable name
TARGET = simple_image_test

HEADERS += imageprovider.h imagesource.h

# Compile these sources
SOURCES += main.cpp imageprovider.cpp imagesource.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Unix executable install path
target.path = $$PREFIX/usr/bin
INSTALLS += target

RESOURCES += qml.qrc resources.qrc
