all: main

main: main.o table.o
        gcc main.o table.o -o main

main.o: main.cpp
        gcc main.cpp

table.o: table.cpp table.h
        gcc table.cpp

clean:
        rm -rf *.o main
