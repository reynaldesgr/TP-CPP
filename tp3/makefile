CXX = g++
CXXFLAGS+=-Wall -Wextra -MMD -g -O2 

all: AB

AB: A.o B.o
	$(CXX) $(CXXFLAGS) -o AB A.o B.o

A.o: A.cpp B.hpp
	$(CXX) $(CXXFLAGS) -c A.cpp

B.o: B.cpp A.hpp
	$(CXX) $(CXXFLAGS) -c B.cpp

clean:
	rm -f program A.o B.o
