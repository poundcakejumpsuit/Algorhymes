CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -pedantic

all: rb_tree clean

rb_tree: rb_tree.o
	$(CXX) -o $@ $^

clean:
	rm *.o