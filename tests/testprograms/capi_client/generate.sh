#!/bin/bash

echo "NOTE, this program uses the src-gen of the main program to ensure
compatibility."
echo
echo "Do you want to regenerate inside /src of main program?"
echo
echo "Hit RETURN twice if you are sure - otherwise hit CTRL-C now!"

read x
echo Once more...
read x

cd ../../../src && ./generate.sh || echo Something failed
