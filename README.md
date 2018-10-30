
Franca - ARA integration project
================================

This project builds a showcase integration between Adaptive AUTOSAR and
non-AUTOSAR-systems represented by a system built on the GENIVI Development
Platform.  

It communicates over interfaces defined by ARA::COM XML format and 
Franca IDL.

Some stuff to remember
----------------------

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
This is to minimize duplication, if they need the exact same basis (e.g same
source code, configuration files, Franca IDL interface, or even the
result of code generation in src-gen). The flip side of that is that a change
for one thing will affect another.

