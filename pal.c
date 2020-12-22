#include <stdio.h>
#include <string.h>

int is_pal(char *str);

int main()
{
    char *str = "ffffffffffffo";
    int ans = is_pal(str);
    if(ans == 0)
    {
        printf("%s pal\n", str);
    }
    else
    {
        printf("%s not spal\n", str);
    }
    return 0;
}

int is_pal(char *str)
{
    int i;
    int len = strlen(str);
    for (i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-i-1])
            return 1;
    }
    return 0;
}
