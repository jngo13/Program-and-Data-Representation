# Justin Ngo
# jmn4fms
# 3/2/20
# Makefile

CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++11

OFILES = hashTable.o timer.o wordPuzzle.o

main: $(OFILES)
	 $(CXX) $(CXXFLAGS) $(OFILES)
	@echo "word search is ready!"

clean:
	-rm -f *.o *~ outputfile/bin/rm -f *.o *~

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp
