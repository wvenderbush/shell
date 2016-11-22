GCC = gcc -g

all: func.o proc.o main.o
	$(GCC) func.o proc.o main.o -o prog

main.o: main.c proc.c func.c
	$(GCC) -c main.c

func.o: func.c func.h
	$(GCC) -c func.c

proc.o: proc.c proc.h
	$(GCC) -c proc.c

clean:
	rm *.o
	rm *~

run: all
	./prog

debug: all
	gdb prog
