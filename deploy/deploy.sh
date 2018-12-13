#!/bin/sh -x

set -e

# Start here in this dir
cd "$(dirname "$0")"

GDP_IP=192.168.100.10
TARGET_DIR=/
SOURCE_DIR=usr

# (Note that scp will follow symlinks by default)
scp -r $SOURCE_DIR root@$GDP_IP:$TARGET_DIR
