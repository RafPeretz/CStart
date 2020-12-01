# All Targets
all: task2

# Tool invocations
task2: task2.o 
	gcc -g -m32 -o filter task2.o

task2.o: task2.c
	gcc -g -m32 -ansi -c -o task2.o task2.c
		
#tell make that "clean" is not a file name!
.PHONY: clean 

clean: 
	rm -f *.o filter
