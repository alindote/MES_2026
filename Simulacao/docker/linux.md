1. Install Docker for your particular system. This tutorial works for Ubuntu releases 16.04 through 21.04, and should also work for other variants such as Linux Mint
    * https://docs.docker.com/engine/install/ubuntu/#
    * Installing from the repository should be the easiest and safest way
    * Make sure to also follow the post-installation steps (https://docs.docker.com/engine/install/linux-postinstall/), in particular create a docker group and add your user to it, and configure Docker to start on boot
2. Test your docker installation:
    1. `$ docker --version`<br>
    should return something like <br>
    _Docker version 19.03.5, build 633a0ea_
    2. Try the “hello-world” Docker image <br>
    `$ docker run hello-world` <br>
    this should pull the image and return a message: <br>
    _Hello from Docker!_ <br>
    _This message shows that your installation appears to be working correctly._
    3. If you have problems running docker and need to run it as _sudo_, then you need to add your user to the docker group. See the post-installation steps above.
3. Create a local folder for your work. This folder will be shared between your local system and the docker image, e.g. <br>
    `$ mkdir -p ~/docker/tutorials` <br>
    `$ cd ~/docker/tutorials`
4. Download and save the two scripts in this repository to the folder you just created (setup_docker.sh and run_docker.sh)
5. Edit the setup_docker.sh script to choose between an image with just C++ and ROOT, or an image which also includes GEANT4 (you'll need to comment/uncomment the line that defines the IMAGE variable). Default is GEANT4.
6. Start the container by running: <br>
    `$ source setup_docker.sh` <br>
(the first time it will take a while, as it needs to download the image)
7. Enter the container by running: <br>
    `source run_docker.sh` <br> 
The current local folder is shared under <br>
    `/shared`

