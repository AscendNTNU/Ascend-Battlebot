# Ascend-Battlebot
Arduino code for battlebot controller. 

Compilation through makefile requires arduino-mk to be installed.

## Compile with docker

```
git submodule update --init --recursive
docker build -t ascend-battlebot .
docker run -it -v $PWD/bin:/Ascend-Battlebot/build-leonardo-atmega32u4:rw ascend_battlebot
```

