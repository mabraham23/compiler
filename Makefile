NAME=mycompiler

all: compiler

run: compiler
	./$(NAME).exe input.c

compiler:
	g++ -std=c++11 *.cpp -o $(NAME).exe

gdb:
	g++ -g -std=c++11 *.cpp -o $(NAME).exe

clean:
	rm *.o *.exe
