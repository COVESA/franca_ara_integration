# Build Franca - ARA integration with GDP

Full instruction on how to setup a build environment for GDP can be found
on the [wiki](https://at.projects.genivi.org/wiki/display/GDP/GDP+Master) and
most of it is applicable in this case as well.

Clone GDP meta data:

    git clone https://github.com/GENIVI/genivi-dev-platform.git

Change directory to `genivi-dev-platform`:

    cd genivi-dev-platform

Clone Franca - ARA integration:

    git clone git@github.com:GENIVI/franca_ara_integration.git

Setup GDP build environment:

    source ./init.sh r-car-m3-starter-kit

Add the `meta-franca-ara` layer to the GDP environment:

    bitbake-layers add-layer ../franca_ara_integration/yocto/meta-franca-ara

Make sure Franca - ARA integration application is installed by adding the
following to `local.conf`:

   IMAGE_INSTALL_append = " franca-ara"

Build GDP image which will include the `franca-ara` integration application:

    bitbake genivi-dev-platform

