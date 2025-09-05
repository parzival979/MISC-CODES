# Getting Started
The first thing to do is to clone this repository.
```
cd $HOME
git clone https://github.com/matthewbdwyer/cs6888-public.git
```

The following instructions all assume you cloned into your ```$HOME``` directory.  

There are two ways to build the image for use in the homeworks.  Building locally works well if you have a machine with enough RAM and disk space, but if you run into problems the second approach of running on ```portal.cs.virginia.edu``` works fine as well.

# Build Docker Image Locally

To do this you must have [Docker](https://www.docker.com/get-started) and [Docker Compose](https://docs.docker.com/compose/install/) installed locally on your machine.  You will not be able to do this on ```portal.cs.virginia.edu``` due to licensing issues with Docker.  You can still use Docker for your personal use on your machine.

Once installed and your docker instance is running you execute the following:
```
cd cs6888-public
docker-compose up --build &
docker-compose exec main bash
```
The final command will drop you into a shell where you execute commands and scripts that we have provided.

# Convert Pre-built Docker Image to Apptainer

If you want to use ```portal.cs.virginia.edu``` then you need to use Apptainer.  This is an alternative container system that does essentially what Docker does.   ```portal``` uses a module system and you need to explicitly load the ```apptainer``` module with this command:
```
module load apptainer
```
You can do add this to your login shell profile if you want to avoid typing it repeatedly.

The first step is to build an Apptainer image, a ```.sif``` file, from a pre-built docker image that I created using the steps above and that is published on Docker hub

```
cd cs6888-public
apptainer build main.sif docker://matthewbdwyer/cs6888-public-main
```
Now you have a local Apptainer image that you can run as follows
```
apptainer run main.sif bash
```
This will give you a shell with a prompt like ```Apptainer>```.  Apptainer does not translate all of the information from the docker image correctly, so to make the homework scripting work within the running Apptainer shell you should execute the following commands:
```
PATH=/root/infer/bin:/root/cppcheck/build/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ln -s $HOME/cs6888-public/files $HOME/files
```
