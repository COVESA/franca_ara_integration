Auto-generated code (do not edit!)
----------------------------------

Comment: 

Auto-generated code is not normally checked into source control - it's a
cleaner process to always exercize the full tool chain by generating the code
as part of the build.   Thus, normally only the .fidl and .fdepl files would
be subject version controlled in git.

For this we're making an exception to simplify the integration of the
generated code (integation can start without putting the whole toolchain fully
in the build chain).  Also it will be possible to track changes in the
generated code (through git diff), which helps for anyone less familiar with
the Common API C++ interface and inner workings.

The decision to keep these source files here can of course be reversed at a
later time.

