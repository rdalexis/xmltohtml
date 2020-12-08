# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

SRC = main.cpp XMLToHTML.cpp XMLParser.cpp
OBJ = $(SRC:.cpp = .o)
MAIN = xmltohtml

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

clean:
	$(RM) *.o *~ $(MAIN)
