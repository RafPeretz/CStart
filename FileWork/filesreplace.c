#include <stdio.h>

int main ()
{
    
    // FILE* foo = fopen("foo.txt", "a");
    // fprintf(foo, "ha gever");


// sa sert a afficher un files sur le terminales:
// par expl la sa affiche tout le contenu de foo.txt sur le trml 
    // FILE* foo = fopen("foo.txt", "r");
    // char buf[100] = "";
    // while(fgets(buf, 100, foo) != NULL)
    // {
    //     printf("%s", buf);
    // }
    // fclose(foo);
    // printf("\n");
    
       int i;
        FILE * fptr;
        char fn[50];
        char str[] ='#' ;
        fptr = fopen("foo.txt", "w"); // "w" defines "writing mode"
        for (i = 0; str[i] != '\n'; i++) 
        {

           if (str[i]=='*')
           {
               fputc(str[i], fptr);
           }
           
           
        }
        fclose(fptr);
        return 0;   
}