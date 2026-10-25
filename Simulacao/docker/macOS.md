1. Install Docker Desktop (https://docs.docker.com/docker-for-mac/install/)
2. Test your docker installation. In a terminal, type:
    1. `$ docker --version`<br>
    should return something like <br>
    _Docker version 19.03.5, build 633a0ea_
    2. Try the “hello-world” Docker image <br>
    `$ docker run hello-world` <br>
    this should pull the image and return a message: <br>
    _Hello from Docker!_ <br>
This message shows that your installation appears to be working correctly.
3. Make sure you have XQuartz installed, you’ll need it to open X11 windows from the Docker image (https://www.xquartz.org)
4. Change XQuartz settings to allow remote connections to open X windows: <br>
    _XQuartz -> Preferences -> Security -> Allow connections from network clients_
5. Create a local folder for your work. This folder will be shared between your local system and the docker image, e.g. <br>
    `$ mkdir -p ~/docker/root` <br>
    `$ cd ~/docker/root`
6. Download and save the two scripts in this repository to the folder you just created (setup_docker.sh and run_docker.sh)
7. Edit the setup_docker.sh script to choose between an image with just C++ and ROOT, or an image which also includes GEANT4 (you'll need to comment/uncomment the line that defines the IMAGE variable). Default is GEANT4.
8. Start the container by running: <br>
    `$ source setup_docker.sh` <br>
(the first time it will take a while, as it needs to download the image)
9. Enter the container by running: <br>
    `source run_docker.sh` <br> 
The current local folder is shared under <br>
    `/shared`


