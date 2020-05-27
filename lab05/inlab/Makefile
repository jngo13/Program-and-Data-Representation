# Justin Ngo
# jmn4fms
# 2/25/20
# Makefile

CXX=clang++
CXXFLAGS=-Wall -o2 -std=c++11

# All of the .o files for the program
OFILES	= BinaryNode.o BinarySearchTree.o BSTPathTest.o

main: $(OFILES)
	$(CXX) $(OFILES)
	@echo "binary search tree is ready!"

clean:
	-rm -f *.o *~ outputfile/bin/rm -f *.o *~

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp
