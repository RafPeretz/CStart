//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//
//// Forawrd Declaration (this function will be used in the code)
//unsigned int hexa_to_int(char str[]); //c'est pour dire que cette function va etre utiliser dans le code 
//int char_to_int(char c);
//
////int main(void)
////{
////	printf("please enter you hexa number: ");
////	char hexa_str[100] = "";
////	scanf("%s", hexa_str);
////
////	unsigned int number = hexa_to_int(hexa_str);
////	printf("your number is: %d\n", number);
////	getchar();
////	getchar();
////	return 0;
////}
////
//
//int main(void)
//{
//	printf("please enter you binary number: ");
//	char binary_str[100] = "";
//	scanf("%s", binary_str);
//	unsigned int number = binary_to_int(binary_str);
//	printf("your number is: %d\n", number);
//	getchar();
//	getchar();
//	return 0;
//}
//
//
//
//
//unsigned int hexa_to_int(char str[])
//{
//	int size = strlen(str);//je comprend pas sa 
//	int power = 0;
//	unsigned int num = 0;
//	for (int i = size - 1; i >= 0; i--)
//	{
//		int digit = char_to_int(str[i]);
//		num += digit * pow(16, power); //this the formule to converte
//		power++;
//	}
//	return num;
//}
//
//unsigned int binary_to_int(char str[])
//{
//
//	int size = strlen(str);
//	int power = 0;
//	unsigned int num = 0;
//	for (int i = size - 1; i >= 0; i--)
//	{
//		int digit = char_to_int(str[i]);
//
//		num += digit * pow(2, i); //this the formule to converte
//		power++;
//	}
//	return num;
//}
//
//int char_to_intbin(char c)
//{
//
//	if (c == '0')
//		return 0;
//	else return 1;
//
//}
//
//int char_to_int(char c)
//{
//	if (c == '0')
//		return 0;
//
//	else if (c == '1')
//		return 1;
//
//	else if (c == '2')
//		return 2;
//
//	else if (c == '3')
//		return 3;
//
//	else if (c == '4')
//		return 4;
//
//	else if (c == '5')
//		return 5;
//
//	else if (c == '6')
//		return 6;
//
//	else if (c == '7')
//		return 7;
//
//	else if (c == '8')
//		return 8;
//
//	else if (c == '9')
//		return 9;
//
//	else if (c == 'A')
//		return 10;
//
//	else if (c == 'B')
//		return 11;
//
//	else if (c == 'C')
//		return 12;
//
//	else if (c == 'D')
//		return 13;
//
//	else if (c == 'E')
//		return 14;
//
//	else
//		return 15;
//}
