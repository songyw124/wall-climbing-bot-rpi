FROM arm64v8/ros:foxy

LABEL title="hero-wc-bot-docker-img"
LABEL author="JungillKang"
LABEL version="1.0"

# create user
RUN apt-get upgrade -y
RUN apt-get update -y
RUN apt-get install x11-apps -y
RUN apt-get update
RUN apt-get install ros-foxy-turtlesim -y
RUN apt-get install ~nros-foxy-rqt* -y
RUN apt-get update
RUN apt-get upgrade -y

# -m = --create-home
RUN useradd -ms /bin/bash hero

WORKDIR /home/hero

# create ws folder
RUN mkdir -p ./data

# change workding directory
WORKDIR ./data

# give the file 
ADD . .

WORKDIR /home/hero

# change user
RUN echo 'hero:hero1210' | chpasswd

# add user to sudo group
RUN usermod -aG sudo hero

USER hero

CMD ["/bin/bash"]
