#!/bin/bash

# This script is used to enter a running docker container
# It must be used after the setup_docker.sh script, and 
# using the same CONTAINER name.
#
# You can comment/uncomment the lines below to select using
# the geant4 user or using the container as user root

CONTAINER=myLinux

# use this line to run enter the container with your user ID
#docker exec -it --user=$(id -u) $CONTAINER bash

# or this one to enter as user root
docker exec -it $CONTAINER bash
