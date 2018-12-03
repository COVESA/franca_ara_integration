#!/bin/sh

# Check if the SOMEIP service ports are opened locally

# Local stuff we don't want to see (depends on computer)
filters='fgrep -v arn09'

dnsfilter='fgrep -v :mdns'

# (As defined in vsomeip.json)
wanted_ports='"1334|1335"'

# This assumes -u UDP, check your vsomeip configuration
watch -n 1 "netstat -aun  | $dnsfilter | $filters | egrep $wanted_ports"

