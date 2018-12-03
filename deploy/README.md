
This directory provides a directory structure that can be immediately
deployed to the GDP target's /usr hierarchy.  Using symlinks we point out the
artifacts that need to be copied.  Scp over ssh can be used to copy the files
to the target board.

It is used only for development since:

# The program will likely be included in a Yocto image build.
# A proper deployment should set permissions correctly so that the program can
read its data while other programs can't.  (Besides, apps are run in bwrap
container anyway, which means additional considerations)
