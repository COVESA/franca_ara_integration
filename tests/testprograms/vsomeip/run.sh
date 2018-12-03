#!/bin/bash -xe
set pipefail

cleanup() {
  echo '---------------------------------------------------------'
  echo 'Cleaning up...'
  echo '---------------------------------------------------------'
  unset VSOMEIP_CONFIGURATION LD_LIBRARY_PATH
  echo Killing server and client
  set -x
  echo
  kill -15 $serverpid $clientpid $vsomeipdpid
  sleep 1
  kill -9 $serverpid $clientpid $vsomeipdpid 2>/dev/null
}

trap cleanup SIGINT SIGTERM

cd "$(dirname "$0")"
export VSOMEIP_CONFIGURATION="$(readlink -f ../../../conf/vsomeip_ecu1.json)"

# Depends on where it's installed but /usr/local is default
export LD_LIBRARY_PATH=/usr/local/lib

set +e
ps aux | egrep -q '[v]someipd'
r=$?
set -e
if [ $r -ne 0 ] ; then
  echo "NO vsomeipd running -- starting vsomeipd"
  vsomeipd &
  vsomeipdpid=$!
fi


sleep 4
echo Starting server
sleep 2
build/server &
serverpid=$!

sleep 3
echo Starting client
sleep 1
build/client &
clientpid=$!



set +x
while true ; do # catch CTRL-C
  sleep 1
done

