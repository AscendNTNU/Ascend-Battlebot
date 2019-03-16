FROM debian:latest

RUN apt-get update && apt-get install -y arduino-mk wget

WORKDIR /software
RUN wget http://downloads.arduino.cc/arduino-1.8.9-linux64.tar.xz \
    && tar -xvf arduino-1.8.9-linux64.tar.xz 
ENV ARDUINO_DIR=/software/arduino-1.8.9

WORKDIR /Ascend-Battlebot
COPY . .

CMD ["make"]
