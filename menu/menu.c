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
  int choice;
	int upperBound = get_limits();
	
  printf("Please make a choice \n");
  display_menu();

  int len = 4;
  int arr1[len];
  int *arr2 = map(arr1, len, my_get);
  int *arr3 = map(arr2, len, iprt);
  int *arr4 = map(arr3, len, abs);
  int *arr5 = map(arr4, len, plus_one);
  int *arr6 = map(arr5, len, cprt);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
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

int iprt(int n) //rints the value of n followed by a new line, and returns n unchanged
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

int my_get(int n) //gnores n, reads a line from stdin, and returns a number given in that line
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

int *map(int *array, int arrayLength, int (*f)(int)) // 
{

  int *mappedArray = (int *)(malloc(arrayLength * sizeof(int)));

  for (int i = 0; i < arrayLength; i++)
  {
    mappedArray[i] = f(array[i]);

    return mappedArray;
  }
}
