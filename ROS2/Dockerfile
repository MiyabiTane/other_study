
# This is an auto generated Dockerfile for ros:ros-base
# generated from docker_images_ros2/create_ros_image.Dockerfile.em
FROM ros:foxy-ros-core-focal

# install bootstrap tools
RUN apt-get update && apt-get install --no-install-recommends -y \
    build-essential \
    git \
    python3-colcon-common-extensions \
    python3-colcon-mixin \
    python3-rosdep \
    python3-vcstool \
    && rm -rf /var/lib/apt/lists/*

# bootstrap rosdep
RUN rosdep init && \
  rosdep update --rosdistro $ROS_DISTRO

# setup colcon mixin and metadata
RUN colcon mixin add default \
      https://raw.githubusercontent.com/colcon/colcon-mixin-repository/master/index.yaml && \
    colcon mixin update && \
    colcon metadata add default \
      https://raw.githubusercontent.com/colcon/colcon-metadata-repository/master/index.yaml && \
    colcon metadata update

# install ros2 packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-foxy-ros-base=0.9.2-1* \
    && rm -rf /var/lib/apt/lists/*

# Get ROS2 code
# https://docs.ros.org/en/foxy/Installation/Ubuntu-Development-Setup.html
RUN sudo apt-get update && apt-get install -y wget
RUN mkdir -p ~/ros2_foxy/src
WORKDIR /root/ros2_foxy
RUN wget https://raw.githubusercontent.com/ros2/ros2/foxy/ros2.repos
RUN sudo vcs import /root/ros2_foxy/src < ros2.repos

RUN rosdep update
RUN rosdep install --from-paths /root/ros2_foxy/src --ignore-src --rosdistro foxy -y --skip-keys "console_bridge fastcdr fastrtps rti-connext-dds-5.3.1 urdfdom_headers"

RUN colcon build --symlink-install

RUN echo ". ~/ros2_foxy/install/local_setup.bash" >> ~/.bashrc 

# to use colcon_cd
RUN echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
RUN echo "export _colcon_cd_root=~/ros2_install" >> ~/.bashrc

# to use cv_bridge
# https://github.com/ros-perception/vision_opencv/tree/ros2/cv_bridge

#pip3 install
RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
RUN sudo python3 get-pip.py
RUN pip3 install -U pip

RUN sudo apt install python3-numpy
RUN sudo apt install -y libboost-all-dev
RUN pip3 install opencv-python

WORKDIR /root/ros2_foxy/src
RUN git clone https://github.com/ros-perception/vision_opencv.git/
WORKDIR /root/ros2_foxy/src/vision_opencv
RUN git checkout ros2

# WORKDIR /root/ros2_foxy/src/vision_opencv
# RUN colcon build --symlink-install

# ローカルファイルのコピー
COPY sub_image.py /root/ros2_foxy/src/vision_opencv/sub_image.py
COPY pub_image.py /root/ros2_foxy/src/vision_opencv/pub_image.py

# for cpp_pubsub
WORKDIR /root/ros2_foxy/src
# ros2 pkg create --build-type ament_cmake cpp_pubsubにほぼ等しい作業
COPY cpp_pubsub /root/ros2_foxy/src/cpp_pubsub
# RUN . ~/ros2_foxy/install/local_setup.bash
# RUN colcon build --packages-select cpp_pubsub
# . install/setup.bash

RUN sudo apt-get -y install vim