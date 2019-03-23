FROM debian:latest

# get dependencies
ENV BUILD_DIR build
RUN apt-get update \
  && apt-get install -y arduino-mk curl \
  && rm -rf /var/lib/apt/lists/*

# setup environment
RUN curl https://downloads.arduino.cc/arduino-1.8.7-linux64.tar.xz > arduino-ide.tar.xz \
  && tar -xvf arduino-ide.tar.xz \
  && mkdir -p $BUILD_DIR

WORKDIR $BUILD_DIR
COPY . .

# build
CMD ["make"]
