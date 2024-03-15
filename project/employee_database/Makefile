output: main.o file.o parse.o
	gcc main.o file.o parse.o -o bin/output -Wall

main.o: src/main.c
	gcc src/main.c -c -o main.o -iquote include -Wall

file.o: src/file.c
	gcc src/file.c -c -o file.o -iquote include -Wall

parse.o: src/parse.c
	gcc src/parse.c -c -o parse.o -iquote include -Wall

clean:
	rm main.o
	rm file.o
	rm parse.o
	rm bin/output # the final program

run:
	bin/output -nf database1.db
	bin/output -f database1.db
	bin/output -f database1.db -n
	bin/output -n database1.db
