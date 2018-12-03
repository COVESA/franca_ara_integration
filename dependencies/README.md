# Dependencies

This directory includes some dependencies only to simplify development.

The app that runs on GDP is built with Yocto and all the dependencies will
instead be provided through SDK for the build-time and through the platform
build for the runtime.  Nonetheless, it can be simpler to do initial
(native) development directly on the laptop.

**build-common-api-cpp-native** is here as a submodule.  
On a fresh git clone it might need init and update:

```
git submodule init --update
```

build-common-api-cpp-native is a script that clones the source code and
builds all the CommonAPI runtimes and vSOMEIP library.  It does not compile,
but instead downloads released binaries for all the code generators.  It
builds two test programs that we do not need here and also the D-Bus
variant which is not used in this project.

During development, the code generators can be run from this location, and
it is possible to install the runtime libraries, either directly on your
machine or perhaps in a docker setup.

To run the setup script:

1. Consider editing the version numbers in the script as needed.
2. Run script:

```
cd dependencies/build-common-api-cpp-native
./build-commonapi.sh
```
Look out for any errors.

### Generating code

Write a script that calls the generators from their path.

Look into:
```
build-common-api-cpp-native/project/cgen/common-api...
```
for the exact path.


### Installing runtime libraries

(On your host, or perhaps in a Docker container)

Make use of the locally downloaded and built libraries that a successful
run of the script has already created:

```
cd dependencies/build-common-api-cpp-native/capicxx-core-runtime/build
sudo make install
cd dependencies/build-common-api-cpp-native/capicxx-someip-runtime/build
sudo make install
```

Take note of the PREFIX i.e. install location (by default /usr/local/{lib,include}
You might want to reconfigure and build again with /usr/{lib,include} for
simplicity.


