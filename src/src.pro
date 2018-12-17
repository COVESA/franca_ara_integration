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

HEADERS += imageprovider.h \
           imagesource.h \
           recognitionmodel.h \
           SomeIpNetworkThread.h \
    SomeIpNetworkThreadTypes.h

# Compile these sources
SOURCES += main.cpp \
           imageprovider.cpp \
           imagesource.cpp \
           recognitionmodel.cpp \
           SomeIpNetworkThread.cpp

# Add generated headers
HEADERS += src-gen/v1/genivi/aasr/showcase/IDrivingLane.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneProxyBase.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneProxy.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPDeployment.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPProxy.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPStubAdapter.hpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneStub.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehicles.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesProxyBase.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesProxy.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPDeployment.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPProxy.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPStubAdapter.hpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesStub.hpp

# Add generated sources
SOURCES += src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPDeployment.cpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPProxy.cpp \
           src-gen/v1/genivi/aasr/showcase/IDrivingLaneSomeIPStubAdapter.cpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPDeployment.cpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPProxy.cpp \
           src-gen/v1/genivi/aasr/showcase/IVehiclesSomeIPStubAdapter.cpp

INCLUDEPATH += src-gen

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += CommonAPI CommonAPI-SomeIP vsomeip automotive-dlt
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Unix executable install path
target.path = $$PREFIX/usr/bin
INSTALLS += target

RESOURCES += qml.qrc resources.qrc
