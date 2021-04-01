FROM arm64v8/ros:foxy

LABEL title="hero-wc-bot-docker-img"
LABEL author="JungillKang"
LABEL version="1.0"

# create user
RUN apt-get update
# -m = --create-home
RUN useradd -ms /bin/bash hero

WORKDIR /home/hero

# create ws folder
RUN mkdir -p /data

# change workding directory
WORKDIR /data

# give the file 
ADD . /data

# change user
USER hero

CMD ["/bin/bash"]
