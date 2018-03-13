CXX      = g++
CXXFLAGS = -g -std=c++11 -O2 -Wall -pedantic

all: rbtree clean

rbtree: rbtree.o
	$(CXX) -o $@ $^

rbtree.o: rbtree.cpp rbtree.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm *.o
