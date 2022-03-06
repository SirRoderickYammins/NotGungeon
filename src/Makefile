UNAME_S = $(shell uname -s)

CC = 
LDFLAGS = ../lib/raylib/libraylib.a
INCLUDE = ../include

ifeq ($(UNAME_S), Darwin)
	CC += clang
	LDFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
endif

ifeq ($(OS),Windows_NT)
	CC += gcc
	LDFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

SRC  = $(wildcard *.c)
BIN = ../bin

dirs:
	mkdir -p ./$(BIN)

game: 
	$(CC) -o $(BIN)/game $(SRC) -I $(INCLUDE) $(LDFLAGS) 
