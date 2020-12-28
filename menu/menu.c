#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declarations
int plus_one(int n);
int *map(int *array, int arrayLength, int (*f)(int));
int absolute(int n);
int iprt(int n);
int cprt(int n);
int my_get(int n);
int quit(int n);
int get_limits();
void display_menu();


typedef struct //class de function
{
  char *name;      // nom de la fonction
  int (*fun)(int); // poourquoi y a besoin de mettre des parenthese et pk un autre int

} function;

function menu[] = //array de la class function
    {
        {"Plus One", plus_one},
        {"Absolute", absolute},
        {"Print Integer", iprt},
        {"Print Character", cprt},
        {"Get numbers", my_get},
        {"Quit", quit},
        {"NULL", NULL}

};

void display_menu() // affiche le menu
{
  int i = 0;

  while (strcmp(menu[i].name, "NULL") != 0) //
  {
    printf("%d) %s\n", i, menu[i].name);
    i++;
  }
}


int *map(int *array, int arrayLength, int (*f)(int)) // 
{

  int *mappedArray = (int *)(malloc(arrayLength * sizeof(int)));

  for (int i = 0; i < arrayLength; i++)
  {
    mappedArray[i] = f(array[i]);

    return mappedArray;
  }

}
int get_limits() // rends la taille du menu
{
  int i = 0;
  while (strcmp(menu[i].name, "NULL") != 0)
    i++;
  return i - 1;
}

void check_choice(int choice, int limits) //verifie si le choix ce trouve dans le menu
{
  if (choice >= 0 && choice <= limits)

    printf("the choice is in the limits of the menu :)");
  else
    printf("ERROR yout choice is not on the menu :(");
}



int main()
{
  int* iarray =(int*)(malloc(4*sizeof(int))); // defini la taille de iarray de 4 et fais apell a la function malloc pour prendre de la place dans le heap

	memset (iarray, 0, sizeof(*iarray)) ; //initialise le array a zero 

	int choice;
	int size_menu = get_limits();//donne la taille du menu 
	
	while (1) // s'arrete quand l'utilisateur apelle la fonction quit
  { 
		char number[16];
		printf("Please choice a function");
		display_menu(); //affice le menu 

		fgets(number, sizeof(number), stdin); // koleth the choice
		sscanf(number, "%d", &choice) ;
		 check_choice(choice, size_menu) ; //verifie si le choix est bon sinon
		function function = menu[choice] ;
		int* mappedArray = map(iarray, 4, function.fun); /* evaluation */
		if (iarray != NULL)
			free(iarray) ;
		iarray = mappedArray ;
		puts ("DONE.\n"); 
	}  
	return 0 ;
}





int plus_one(int n) //ajoute 1 a un nombre
{
  return n + 1;
}

int absolute(int n) //rend la valeur absolue 
{
  if (n > 0)
    return n;

  else
  {
    n = n * -1;
    return n;
  }
}



int iprt(int n) // prints the value of n followed by a new line, and returns n unchanged
{
  printf("%d \n", n);
  return n;
}

int cprt(int n) //  Prints the character of ASCII value n followed by a new line, and returns n unchanged. 
                //    If n is not between 0x20 and 0x7E, print the dot ('.') character instead.
{
  if (n < 32 || n > 126)
    printf(".\n");
  else
    printf("%c\n", n);
  return n;
}

int my_get(int n) // ignores n, reads a line from stdin, and returns a number given in that line
{
  char number[16];
  int myNum;
  fgets(number, sizeof(number), stdin);
  sscanf(number, "%d", &myNum);
  return myNum;
}

int quit(int n) // quit le process
{
  exit(n);
  return n;
}



