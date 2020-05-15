# Justin Ngo
# jmn4fms
# 4/21/20
# Lab 10 Makefile

CXX=clang++ -O2 -std=c++11

CXXFLAGS=-Wall -g -O2

OFILES= traveling.cpp middleearth.cpp

.SUFFIXES: .o .cpp

main: $(OFILES) 
	$(CXX) $(DEBUG) $(OFILES)
	doxygen
clean:
	/bin/rm -f *.o *.~

traveling.o: traveling.cpp