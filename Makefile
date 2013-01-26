all: onionworld

GLCFLAGS=$(shell pkg-config --cflags gl)
CFLAGS=-Wall -O2 ${GLCFLAGS}

GLLIBS=$(shell pkg-config --libs gl)
LIBS=${GLLIBS} -lglut

onionworld: main.o
	gcc $? ${LIBS} -o onionworld 

%.o: %.cpp
	gcc ${CFLAGS} -c $<

clean:
	rm -f *.o onionworld
