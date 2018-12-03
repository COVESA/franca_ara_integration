#!/bin/bash

echo "NOTE, this program uses the src-gen of the simple_capi_client, to ensure
compatibility."
echo
echo "Do you want to regenerate inside simple_capi_**client** directory?"
echo
echo "Hit RETURN twice if you are sure - otherwise hit CTRL-C now!"

read x
echo Once more...
read x

cd ../simple_capi_client && ./generate.sh || echo Something failed
