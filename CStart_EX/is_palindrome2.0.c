#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//FORWARD DECLARATION 
char* strdup(const char* str); 
int isPalindrome(char *s);
char *strrev(char *str);
void copy_string(char *target, char *source);
void reverse_string(char *string);
int strlen_raf(char *ch);
void reverse_string(char *string);


int main()
{
 


  char *ch ="rafa";
   int size =strlen_raf(ch);
   printf("%d\n",size);
   char *a = (char*)10;
   *a = 'h';

   printf("DONE\n");


 // ex3 

 	char string[100];
 	int result;
 	 printf("Input a string\n");
      fgets(string,100,stdin);
     string[strlen(string)-1] = 0; 

 	
   result = isPalindrome(string);
 
   if (result == 1)
      printf("\"%s\" is a palindrome string.\n", string);
   else
      printf("\"%s\" isn't a palindrome string.\n", string);
 
   return 0;

	// char arr [100];
	// printf("Enter a string to convert to int \n");

	// fgets(arr,100,stdin);
	// int b = atoi(arr);
 //   printf(" your num is :%s\n",arr);
 //   b=b*10;
 //   printf("%d\n",b);


	//   char *num_string=NULL;
	 // num_string = malloc(sizeof(char));

  // printf("Enter a string to convert to int \n");
   //fgets(num_string,strlen(num_string),stdin);
   //atoi(num_string);
   //printf("%s\n",num_string);
   //free(num_string);
}

int isPalindrome(char *s)

{

	int size;
  	int count=0; 
  	char *reverse;

  	size =strlen(s);
  	reverse = (char*)malloc(size+1); 

  	copy_string(reverse, s); 
  	reverse_string(reverse);

	 

  	for (int i = 0; i < size; i++)
  	{
  		
  			if ((s[i]==reverse[i]))
  			{
  				count ++;
  			}

  		
  	}

  	free(reverse);

  	if(count==size)
  		return 1; 

  	else
  	 	return 0;



}




char* strdup(const char* str)
{
      char* newstr = (char*) malloc( strlen(str) + 1);

      if (newstr) 
      {
          strcpy( newstr, str);
      }

      return newstr;
}


void copy_string(char *target, char *source) // copy_string(buf, 'aba')
{
   while(*source)
   {
      *target = *source;
      source++; 
      target++;
   }
   *target = '\0';
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


void reverse_string(char *string)
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(string);
 
   begin = string;
   end = string;
 
   for (c = 0; c < (length - 1); c++)
       end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

int strlen_raf(char *ch)
{
   int count= 0;
   
   while(*ch!='\0')
   {
      ch++;
      count++;
   }

   return count;
  

}


