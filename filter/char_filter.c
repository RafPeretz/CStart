#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h> 

//forward deckaration 
char *filter_char(char* ch_array,char ch); 


int main(int argc, char *argv[])
{

	if (argc > 2)
	{
		printf("Error: more than one argument to main\n");
		return 1;
	}

	char* to_filter = argv[1];

	printf("to_filter: %s\n", to_filter);
	goto end;

	char str[20] = "";

	printf("Please enter your string: ");
	fgets(str, 20, stdin);

	printf("Please enter your char you want to remove: ");
	char ch = getchar();


	

	char* p = filter_char(str,ch);

	printf("%s\n", p);
	free(p);

	end:
		printf("END\n");
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