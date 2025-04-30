g++ -c main.cpp -o main.o
g++ -c ../src/test.cpp -o test.o
g++ main.o test.o -o my_program
