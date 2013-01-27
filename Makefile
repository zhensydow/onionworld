
all: onionworld

GLCFLAGS=$(shell pkg-config --cflags gl)
CFLAGS=-std=c++11 -Wall -O2 ${GLCFLAGS}

GLLIBS=$(shell pkg-config --libs gl)
LIBS=${GLLIBS} -lglut -lstdc++

onionworld: main.o shaders.o fileutils.o
	gcc $^ ${LIBS} -o onionworld

%.o: %.cpp
	gcc ${CFLAGS} -c $<

clean:
	rm -f *.o onionworld
