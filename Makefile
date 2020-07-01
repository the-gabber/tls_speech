#Detect OS
OSNAME=$(shell uname)
ifeq ($(OSNAME),Linux)
DSO_EXT=so
else
DSO_EXT=dylib
#STD_LIB=-stdlib=libc++
endif

CC= clang++
CXXFLAGS= -std=c++17 -Os $(STD_LIB) #-g
LDFLAGS=  $(STD_LIB)

