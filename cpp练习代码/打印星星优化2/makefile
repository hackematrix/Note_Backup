star:demo.o main.o
	g++ demo.o main.o -o star

demo.o:demo.cpp
	g++ -c demo.cpp -o demo.o

main.o:main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o