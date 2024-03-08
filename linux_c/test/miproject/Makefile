all: program program2

objs := main.o proj.o
objs_2 := calc.o

program: $(objs)
	gcc $(objs) -o program

main.o: main.c
	gcc -c -g main.c -o main.o -Wall

proj.o: proj.c
	gcc -c -g proj.c -o proj.o -Wall

clean_program:
	rm main.o proj.o
	rm program

program2: $(objs_2)
	gcc $(objs_2) -g -o program2

calc.o: calc.c
	gcc -c calc.c -o calc.o

clean_program2:
	rm calc.o
	rm program2

print: $(wildcard *.c)
	ls -la $?
