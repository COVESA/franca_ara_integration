# Copyright (C) 2018 GENIVI Alliance
# Released under the MIT license (see COPYING.MIT for the terms)
SUMMARY = "Franca - ARA Integration Demo"
HOMEPAGE = "https://github.com/GENIVI/franca_ara_integration"
LICENSE  = "MPL-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9741c346eef56131163e13b9db1241b3"

DEPENDS = "qtbase qtdeclarative common-api-c++-someip"

SRC_URI = "\
    git://git@github.com/GENIVI/franca_ara_integration;protocol=ssh;branch=skeleton-code \
    file://${APPLICATION_DESKTOP_FILE} \
"
SRCREV = "${AUTOREV}"

APPLICATION_DESKTOP_FILE = "com.genivi.gdp.franca.ara.desktop"
APPLICATION_BIN = "${B}/franca-ara"
APPLICATION_ICON = "${S}/com.genivi.gdp.franca.ara.svg"
APPLICATION_UNIT = "com.genivi.gdp.franca.ara"

require recipes-dev-hmi/genivi-dev-platform-hmi/apps.inc
