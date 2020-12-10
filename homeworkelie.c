#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int is_palindrome(char*);
void copy_string(char*, char*);
void reverse_string(char*);
int string_length(char*);
int compare_string(char*, char*);
 
int main()
{


//test strlen  (ex3)

   char *str= "hey";
   int size_str=strlen(str);
   printf("%d\n", size_str);


   char arr[10]  ={'a','b','c'};
   int size_arr =strlen(arr);
   printf("%d\n", size_arr);

   char arr2[20] = "12345";
   int size_arr2= strlen(arr2);
   printf("%d\n",size_arr2);

   /// end test 


   char string[100];
   int result;
   //char *ch ="rafa";
   char *num_string;

   printf("Enter a string to convert to int \n");
   fgets(num_string,strlen(num_string),stdin);
   atoi(num_string);
   printf("%s\n",num_string);


  // reverse_string(ch);
  // printf("%s\n",ch);


   printf("Input a string\n");
      fgets(string,1000,stdin);

 
   result = is_palindrome(string);
 
   if (result == 1)
      printf("\"%s\" is a palindrome string.\n", string);
   else
      printf("\"%s\" isn't a palindrome string.\n", string);
 
   return 0;
}
 
int is_palindrome(char *string)
{
   int check, length;
   char *reverse;
 
   length = string_length(string);    
   reverse = (char*)malloc(length+1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   if (check == 0)
      return 1;
   else
      return 0;
}
 
int string_length(char *string)
{
   int length = 0;  
 
   while(*string)
   {
      length++;
      string++;
   }
 
   return length;
}
 

 
void reverse_string(char *string)
{
   int length, c;
   char *begin, *end, temp;
 
   length = string_length(string);
 
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
 
int compare_string(char *first, char *second)
{
   while(*first==*second)
   {
      if (*first == '\0' || *second == '\0')
         break;
 
      first++;
      second++;
   }
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}


// ex2
void copy_string(char *target, char *source)
{
   while(*source)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = '\0';
}

//ex3 


