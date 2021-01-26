#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h> 

//forward deckaration 
char *filter_char(char* ch_array,char ch); 

int main ()
{
	char str[] = "abcd";
	char ch ='d';
	int n = strlen(str);
	int c = 0;

	char* p = filter_char(str,ch);


	printf("%s\n", p);
	free(p);

	return 0;

}

char *filter_char(char* ch_array,char ch )
{

	char *new_arr = (char*)malloc(strlen(ch_array) * sizeof(char));
	int idx = 0;


	for (int i = 0; i < strlen(ch_array); i++)
	{
	  if(ch != ch_array[i])
	  {
	  	new_arr[idx] = ch_array[i];
	  	idx++;
	  }

	}

	return new_arr;

}