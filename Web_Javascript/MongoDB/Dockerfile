FROM ubuntu:20.04
MAINTAINER MiyabiTane <tanemoto@jsk.imi.i.u-tokyo.ac.jp>

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
       apt-utils \
       sudo \
       vim \
       tmux \
       git \
    && apt-get -y clean \
    && rm -rf /var/lib/apt/lists/*

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# RUN groupadd -g 1000 developer && \
#     useradd  -g      developer -G sudo -m -s /bin/bash ubuntu && \
#     echo 'ubuntu:ubuntu' | chpasswd

RUN echo 'Defaults visiblepw'            >> /etc/sudoers
RUN echo 'ubuntu ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

RUN sudo apt-get update
RUN sudo apt-get -y upgrade
RUN sudo apt-get install -y vim
RUN sudo apt install -y nodejs
RUN sudo apt-get install -y aptitude
# RUN sudo apt install npm
RUN apt-get update -y && apt-get install -y expect
COPY install_npm.exp .
RUN expect install_npm.exp
WORKDIR /root
COPY ros_entrypoint.sh /ros_entrypoint.sh
RUN chmod u+x /ros_entrypoint.sh
RUN apt install -y mongodb
RUN npm install mongodb

WORKDIR test 
COPY encoding.js ../node_modules/whatwg-url/dist/encoding.js
COPY operate_data.js .
