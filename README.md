
Franca - ARA integration project
================================

This project builds a showcase integration between Adaptive AUTOSAR and
non-AUTOSAR-systems represented by a system built on the GENIVI Development
Platform.  

It communicates over interfaces defined by ARA::COM XML format and 
Franca IDL.

Dependencies
-------------

Roughly the following packages are needed.  If compiled and installed
manually, they should be found by QtCreator via pkgconfig.

PackageName (source-repository-name):

CommonAPI (capicxx-core-runtime)
CommonAPI-SomeIP (capicxx-someip-runtime)
vsomeip (vsomeip)
automotive-dlt (dlt-daemon)

Development
-----------

WARNING: This is not "nicely" packaged or fully documented.  If you are
working with this, you may need to do a bit of tweaking, but the following
info should provide some starting points at least.

* Patches, send them as PRs on the GitHub repository.
* Code-specific issues or questions about code (not general support help)-
GitHub Issues.  Note that processing them might be fairly low priority.
* General questions or contact: genivi-projects (at) lists.genivi.org or ask
around

Compiling and testing for Target Systems
----------------------------------------

Specific support for different target OSes is stored in different places.

1. For GENIVI Development Platform, the instructions are encoded in
OpenEmbedded/Yocto "bitbake" files inside the genivi-development-platform 
repository -- (see branch ces_demo if not found on master)

2. For other platforms, such as Apertis, WebOS, etc. this is Work-in-progress
   and TBD

Compiling and testing on Development Host (and general info)
------------------------------------------------------------

* You need a system with bash shell, probably.   Only Linux dev host has been
tested.

* If you are going to run any generate.sh script, first make sure the
submodule in dependencies/build-common-api-cpp-native is cloned (see README in
dependencies/), and that the project script therein has been run at least once
because the code-generation binaries are fetched from that path.

* The main IVI application program (for GDP) is mostly in src/ .  The
command-line test programs are under tests/testprograms.

* The intermediate test programs were used for development but also serve as
examples and are useful for getting printouts of the communication.

* Programs will need link against CommonAPI runtime, CommonAPI SOME/IP
runtime, vSOMEIP, and in many cases, DLT.  You will need to have those
libraries installed on your development host environment.
To compile in QtCreator, you may need to adjust the search paths.
If libraries are stored in /usr/local then this environment was set
up before launching QtCreator in that shell: 

```
export LD_LIBRARY_PATH=/usr/local/lib
```

There might be other ways to adjust the search path within the project
instead, patches welcome.

* The main program depends on Qt 5 libraries.  Not sure exactly which minimum
version - just use a fairly modern one.

* Most of the intermediate test programs have a script ./build.sh to build
but some of the programs, including the main program are instead compiled with
cmake.   e.g:  mkdir build ; cd build ; cmake .. ; make

* Most of the programs have ./run.sh to run them.  You may need to adjust
some paths in the script, such as library search paths.

* In some cases run.sh starts multiple programs (read all scripts before
running them).

* Most test programs expect some routing manager to be started.  Even if a
routing manager is sometimes created by default, we recommend to run
vsomeip/run.sh to ensure that vsomeipd is started.  Note however that script
also starts a vsomeip/server and vsomeip/client!  You may want to comment that
out if you intend to run capi_client or simple\_capi\_{server,client} in some
combination instead.  More than one client should work in theory but just
know that in some cases running more than one server or more than one client
might conflict.

* Be mindful that many test program dirs refer to other dirs through symlinks,
This is to minimize duplication, if they need the exact same input (e.g same
source code, configuration files, Franca IDL interface, or even the
result of code generation in src-gen). The flip side of that is that a change
for one thing will affect another.

* The "video" frames are provided as a set of individual images at the moment.
Download the file "video.tar" from the Releases tab on GitHub.  Unpack onto
your development or target system -- currently path is hard-coded to
"/usr/local/share/franca-ara/images" - feel free to edit.
