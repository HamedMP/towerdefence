CC = g++
CCMAC = gcc
CFLAGS= -c -ansi -pedantic -std=c++0x -Weffc++ -g -I./include
#INCLUDE =-I../
#MOVE = /bin/mv -f
#RM = /bin/rm -f
#BIN = ./bin


EXE=main
# EXE=bin/exec
LIBS=-L./libMac -lEngine -framework OpenGL -framework GLUT
# LIBS=  -L./libLinux -lEngine -lGL -lglut -lm -lGLU
LDFLAGS= -lm -g -lstdc++

SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp )
ENTETES = $(wildcard src/*.h src/*/*.h src/*/*/*.h)

OBJS = ${SOURCES:.cpp=.o}
includes = $(wildcard src/*.h)

mac: ${OBJS}
	${CCMAC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBS}

linux: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSLINUX}

windows: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSWINDOWS}

ifdef DEBUG
	CFLAGS += -g
endif


all:	${OBJS}
	${CCMAC}  ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBS}

%.o:%.cpp ${includes}
	${CCMAC} -o $@ -c $< ${INCLUDE} $(CFLAGS)

run:
	./main

.PHONY: clean veryclean

clean : #pas de dependance
	/bin/rm -f *.o *.gch *.bak *~ src/*.o src/*/*.o src/*/*/*.o

veryclean : clean
	/bin/rm -f ${EXE}
