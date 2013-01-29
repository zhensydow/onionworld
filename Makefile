
all: onionworld

GLCFLAGS=$(shell pkg-config --cflags gl)

CPPFLAGS=-Wall -O2 ${GLCFLAGS}
CXXFLAGS=-std=c++11

GLLIBS=$(shell pkg-config --libs gl)
LIBS=${GLLIBS} -lglut -lstdc++

onionworld: main.o shaders.o fileutils.o
	${CXX} $^ ${LIBS} -o onionworld

clean:
	rm -f *.o onionworld
