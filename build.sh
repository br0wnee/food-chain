#!/bin/zsh

g++  src/*.cpp -o foodchain -lraylib -lm -ldl -lpthread -lX11 -lxcb -lGL -lGLX -lXext -lGLdispatch -lXau 
