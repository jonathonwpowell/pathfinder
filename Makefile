CC = g++
WARN = -Wall
OPT = -I


FLAGS = $(OPT) $(WARN) 
SRC = tester.cc pathfinder.cc

all: 
	$(CC) -o path_finder_test $(FLAGS) $(SRC) -lm
	@echo "Compiled Successfully"
