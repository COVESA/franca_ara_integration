# Copyright (C) 2018 GENIVI Alliance
# Released under the MIT license (see COPYING.MIT for the terms)
SUMMARY = "Franca - ARA Integration Demo, image test binary"
HOMEPAGE = "https://github.com/GENIVI/franca_ara_integration"
LICENSE  = "MPL-2.0"
LIC_FILES_CHKSUM = "file://${TOP}/LICENSE;md5=9741c346eef56131163e13b9db1241b3"

DEPENDS = "qtbase qtdeclarative"

# FIXME: Should of course not use pr/image_test branch in the final version
SRC_URI = "\
    git://git@github.com/GENIVI/franca_ara_integration;protocol=ssh;branch=pr/image_test \
    file://${APPLICATION_DESKTOP_FILE} \
"
SRCREV = "${AUTOREV}"

TOP = "${WORKDIR}/git"

S = "${WORKDIR}/git/tests/testprograms/simple_image_test"

APPLICATION_DESKTOP_FILE = "com.genivi.gdp.franca.ara.imagetest1.desktop"
APPLICATION_BIN = "${B}/simple_image_test"
APPLICATION_ICON = "${S}/com.genivi.gdp.simple.image.test.svg"
APPLICATION_UNIT = "com.genivi.gdp.franca.ara.imagetest1"

require recipes-dev-hmi/genivi-dev-platform-hmi/apps.inc
