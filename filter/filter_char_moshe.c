#include <stdio.h> 
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
	
// forward declaration
int is_in_string(char curr, char to_remove[]);
char filter(char, char*); 


void main()
{
	char str[20] = "Hi, my name is Noah";//j ai rajouter = et se qui vas apre par rapport au prochain commenter 
	char to_remove[20] = "HI";
	char *filter_str = filter(to_remove, str);

	printf("%s\n", filter_str);
	free(filter_str);

	char c = '[';
	printf("%d\n", c);

	char up = my_up('a');
	char low = my_low('B');
	printf("%c%c", up, low);
}

int is_in_string(char curr, char to_remove[])
{
	for (int i = 0; i < strlen(to_remove); i++)
	{
		if (curr == to_remove[i] || curr == toupper(to_remove[i]) || curr == tolower(to_remove[i]))
			return 1;
	}
	return 0;
}

char filter(char to_remove, char* str)//fonctin de base 
{
	char ans = (char)malloc(strlen(str) * sizeof(char));
	int ans_idx = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (is_in_string(str[i], to_remove) == 0)
		{
			ans[ans_idx] = str[i];
			ans_idx++;
		}
	}
	ans[ans_idx] = 0;
	return ans;
}
char my_up(char c) // je sais pas sa fait quoi 
{
	return c - 32;
}

char my_low(char c)
{
	return c + 32;
}