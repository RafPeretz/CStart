#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abs(int);
int iprt(int);
int cprt(int);
int my_get(int);
int quit(int);
int plus_one (int) ;
int* map (int*, int, int (*f) (int)) ;

typedef struct {
	char* name;
	int (*fun) (int);
} fun_desc ;

	fun_desc menu[] = { {"Plus One", plus_one}, {"Abs", abs}, {"Print Integer", iprt}, {"Print Character", cprt},
		{"Get numbers", my_get}, {"Quit", quit}, {"NULL", NULL}}; /* 2 */

/*
 Displays a prompt asking the user to choose a function by its number in the menu.
 Return the upperBound of the menu.
 */
void displayMenu() {
	int i=0;
	while (strcmp(menu[i].name, "NULL") != 0) {
		printf("%d) %s\n", i, menu[i].name) ;
		++i ;
	}
}

/* Check if the choice is valid*/
void checkValidChoice (int choice, int upperBound) {
	if (choice >=0 && choice<=upperBound) {
		printf("OPTION: %d\nwithin bounds\n", choice) ;
	}
	else {
		puts ("not within bounds") ;
		exit(1) ; /* terminate gracefully */
	}
}

/* Returns the upper bound of menu */
int getUpperBound () {
	int i=0;
	while (strcmp(menu[i].name, "NULL") != 0) 
		++i ;
	return i-1 ;
}

int main(int argc, char **argv){ // char** 
	int* iarray =  (int*) (malloc (4*sizeof(int))) ; /* Defines an int array named 'iarray' of length 4. */
	memset (iarray, 0, sizeof(*iarray)) ; /* Initialize the given array to zero */
	int choice;
	int upperBound = getUpperBound ();
	
	while (1) { /* exit when the user chose Quit*/
		char number[16] ;
		puts ("Please choose a function: ") ; /* Displays a prompt asking the user to choose a function by its number in the menu */
		displayMenu() ; /* Displays a menu */
		fgets(number, sizeof(number), stdin) ;
		sscanf(number, "%d", &choice) ;
		checkValidChoice (choice, upperBound) ; /* if the choice invalid, the program exits.*/
		fun_desc function = menu[choice] ;
		int* mappedArray = map(iarray, 4, function.fun); /* evaluation */
		if (iarray != NULL)
			free(iarray) ;
		iarray = mappedArray ;
		puts ("DONE.\n"); 
	}  
	return 0 ;
}

int* map(int *array, int arrayLength, int (*f) (int)) {
	int jumpSize = 2 ;
	int* mappedArray = (int*) (malloc(arrayLength*sizeof(int)));
	int i;
	for (i=0; i<arrayLength; i=i+jumpSize) {
		int value = array[i];
		int newValue = f(value) ;
		mappedArray[i] = newValue ;
	}
	return mappedArray;
}

int plus_one(int n) {
	return n+1;
}

int abs (int n) {
	if (n>=0) return n ;
	else return -n ;
}

int iprt(int n) {
	printf("%d\n", n);
	return n ;
}

int cprt(int n) {
	if (n<32 || n>126) printf (".\n") ;
	else printf ("%c\n", n);
	return n ;
}

int my_get(int n) {
	char number[16] ;
	int myNum ;
	fgets(number, sizeof(number), stdin) ;
	sscanf(number, "%d", &myNum);
	return myNum;
}

int quit (int n) {
	exit(n) ;
	return n ;
}



