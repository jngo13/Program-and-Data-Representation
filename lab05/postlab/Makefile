# Justin Ngo
# jmn4fms
# 2/25/20
# Makefile

CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++11

# All of the .o files for the program
OFILES	= AVLTree.o AVLNode.o AVLPathTest.o

main: $(OFILES)
	$(CXX) $(OFILES)
	@echo "AVL tree is ready!"

clean:
	-rm -f *.o *~ outputfile/bin/rm -f *.o *~

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLTree.cpp

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp
