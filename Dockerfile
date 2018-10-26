FROM debian:latest

RUN apt-get update && apt-get intsall -y arduino-mk
