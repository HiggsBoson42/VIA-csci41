a.out: main.o
	g++ -g -O3 -std=c++17 main.o

main.o: heap.h node.h main.cc
	g++ -g -O3 -std=c++17 -c main.cc

clean:
	rm -f a.out core *.o
