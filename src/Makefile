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

ifeq ($(UNAME_S), Linux)
	CC += gcc
	LDFLAGS += -lGL -lm -lpthread -ldl -lrt -lX11
endif


SRC  = $(wildcard *.c)
BIN = ../bin

dirs:
	mkdir -p ./$(BIN)

game: 
	$(CC) -o $(BIN)/game $(SRC) -I $(INCLUDE) $(LDFLAGS) 
