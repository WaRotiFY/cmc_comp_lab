all: program.exe

main.o: main.c funcs.h test.h my_task.h
	gcc -m32 -std=c99 -c -o main.o main.c

funcs.o: funcs.asm
	nasm -f win32 -o funcs.o funcs.asm

root.o: root.c root.h
	gcc -m32 -std=c99 -c -o root.o root.c

integral.o: integral.c list.h
	gcc -m32 -std=c99 -c -o integral.o integral.c

list.o: list.c list.h
	gcc -m32 -std=c99 -c -o list.o list.c

test.o: test.c root.h integral.h test_funcs.h
	gcc -m32 -std=c99 -c -o test.o test.c

test_funcs.o: test_funcs.c
	gcc -m32 -std=c99 -c -o test_funcs.o test_funcs.c

my_task.o: my_task.c root.h integral.h funcs.h
	gcc -m32 -std=c99 -c -o my_task.o my_task.c

program.exe: main.o funcs.o root.o integral.o test.o test_funcs.o my_task.o list.o
	gcc -m32 -o program.exe main.o funcs.o root.o integral.o test.o test_funcs.o my_task.o list.o

clean:
	del *.o *.exe