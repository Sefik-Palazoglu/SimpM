TESTS=add normalize scale swap visual_input 
INCLUDEDIR=../include
FLAGS=-std=c++17 -lgmp -lgmpxx
SRCDIR=../src
SRC=$(SRCDIR)/matrix.cpp
DATAFILE=./data-1.txt

all: $(TESTS)

add:
	./test_add.out $(DATAFILE)

normalize:
	./test_normalize.out $(DATAFILE)

scale:
	./test_scale.out $(DATAFILE)

swap:
	./test_swap.out $(DATAFILE)

visual_input:
	./test_visual_input.out $(DATAFILE)

test_add.out: test_normalize.cpp
	g++ $(FLAGS) -I$(INCLUDEDIR) test_add.cpp $(SRC) -o test_add.out

test_normalize.out: test_normalize.cpp
	g++ $(FLAGS) -I$(INCLUDEDIR) test_normalize.cpp $(SRC) -o test_normalize.out

test_scale.out: test_scale.cpp
	g++ $(FLAGS) -I$(INCLUDEDIR) test_scale.cpp $(SRC) -o test_scale.out

test_swap.out: test_swap.cpp
	g++ $(FLAGS) -I$(INCLUDEDIR) test_swap.cpp $(SRC) -o test_swap.out

test_visual_input.out: test_visual_input.cpp
	g++ $(FLAGS) -I$(INCLUDEDIR) test_visual_input.cpp $(SRC) -o test_visual_input.out