objs := main.o file.o parse.o
output: $(objs)
	gcc main.o file.o parse.o -o bin/output -Wall

main.o: src/main.c
	gcc src/main.c -c -o main.o -iquote include -Wall

file.o: src/file.c
	gcc src/file.c -c -o file.o -iquote include -Wall

parse.o: src/parse.c
	gcc src/parse.c -c -o parse.o -iquote include -Wall

clean:
	rm $(objs)
	rm bin/output # the final program

run:
	valgrind bin/output -nf database1.db # Create a database file
	valgrind bin/output -f database1.db # Vaildate file format
	valgrind bin/output -f database1.db -a "Tom,123 Sline lin,12" # Add a new entry to database
	valgrind bin/output -lf database1.db

print:
	echo $(wildcard src/*.c)
