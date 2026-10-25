#!/bin/bash

# Usage: source setup_docker.sh
# This script can be used in Linux and MacOS
# It will retrieve the docker image defined in IMAGE if not present 
# locally and start a container sharing the local current folder 
# where the script is used to /shared inside the container
#
# After this, you can use the run_docker.sh to start a session
# inside the running container

#IMAGE=rootproject/root
#IMAGE=alexlindote/geant4-qt
IMAGE=opengatecollaboration/gate:9.0
CONTAINER=myLinux

# stop running container
docker stop $CONTAINER
docker rm $CONTAINER

# use '--privileged' only if normal settings do not work
EXTRA=""
#EXTRA="--privileged"

# Default display variable (for Linux)
DISP=$DISPLAY

#do some OSX setup for xforwarding
OS="$(uname -s)"
if [ ${OS} = "Darwin" ]; then
    xhost + 127.0.0.1 # X11 forwarding to host
    DISP=host.docker.internal:0
fi

docker run -i -d -t --name $CONTAINER \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v "$PWD:/usershared" \
    $EXTRA -e DISPLAY=$DISP \
    $IMAGE
