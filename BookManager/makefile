CXX=g++
CXXFLAGS=-Wall -fsanitize=address,leak
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean run

all: main

run: main
	echo "\n" && ./main

# $^ - this variable holds all dependencies of given target
main: main.o Book.o
	${CXX} ${LDFLAGS} main.o Book.o -o main

# $< - this variable holds only first dependency of given target
# $@ - this variables holds the target itself
main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp -o main.o

Book.o: Book.cpp
	${CXX} ${CXXFLAGS} -c Book.cpp -o Book.o

clean:
	rm -f *.o main