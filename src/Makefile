UNAME_S = $(shell uname -s)

CC = clang
LDFLAGS = ../lib/raylib/libraylib.a
INCLUDE = ../include

ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
endif

SRC  = $(wildcard *.c)
BIN = ../bin

dirs:
	mkdir -p ./$(BIN)

game: 
	$(CC) -o $(BIN)/game $(SRC) -I $(INCLUDE) $(LDFLAGS) 
