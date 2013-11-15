#Compiler is G++ from MinGW
CC = g++

#Library directory
LDIR = C:/OpenGL/lib

#Include directory
IDIR = ./include -IC:/OpenGL/include

#Source directory
SDIR = ./src

#.o Directory
ODIR = ./obj

#Arguments to pass to the compiler
CFLAGS = -std=c++11 -Wall -I$(IDIR)

#Libraries that will be used
LIBS = -L$(LDIR) -lglfw3dll -lglu32 -lopengl32 -lglew32 

#Removes the console window on release
RELEASE = -Wl,-subsystem,windows

#Dependancies
_DEPS = $(wildcard *.h)
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#Source Files
_SRC = Main.cc Application.cc View.cc Controller.cc \
Screen.cc Camera.cc Terrain.cc \
Shader.cc SimplexNoise.cc VboIndexer.cc 

#Objects
_OBJ = $(_SRC:.cc=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#Executable name
EXECUTABLE = Main


all: $(EXECUTABLE)

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $<

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

run:
	./$(EXECUTABLE)

.PHONY: clean cleanest

clean:
	del obj\*.o

cleanest: clean
	del $(EXECUTABLE).exe