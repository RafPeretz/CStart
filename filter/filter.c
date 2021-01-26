//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include<stdlib.h>
//
//
////Forawrd Declaration(this function will be used in the code)
//int * filterMultiple(int arr[], int size);
//char *filter2(char str[], char ch,int size);
//
//int main()
//{
//	/*int arr_multiple[] = { 1,1,1,2,2,3 };*/
//	char arr_char[] = { 'a','b','c' };
//	int size = 6;
//
//	char ch = 'a';
//
//	//int *new_arr = filtermultiple(arr_multiple, size);
//	char *newchar_arr = filter2(arr_char, ch, size);
//
//	/*for (int i = 0; i < 6; i++)
//	{
//		printf("%d\n", new_arr[i]);
//
//	}*/
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%c\n", newchar_arr[i]);
//	}
//	//free(new_arr);
//	free(arr_char);
//
//
//	getchar();
//}
//
//int *filterMultiple(int arr[], int size)
//{
//	int count = 0;
//	int *new_arr = (int*)malloc(size * sizeof(int));
//
//	for (int i = 0; i < size; i++)
//	{
//		new_arr[i] = 0;
//	}
//
//	int idx = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (arr[i] == arr[j])
//				count++;
//		}
//
//		if (count == 1)
//		{
//			new_arr[idx] = arr[i];
//			idx++;
//		}
//		//efface
//		count = 0;
//	}
//	return new_arr;
//}
//
//
//
//
//char *filter2(char str[], char ch, int size)
//{
//
//
//	int *position = (int*)malloc(size * sizeof(int));
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		if (str[i] == ch)
//			position = &str[i];
//
//
//		for (i = position - 1; i < size - 1; i++)
//		{
//			str[i] = str[i + 1];
//		}
//
//
//	}
//
//	return (str);
//}
//
////int main(void)
////{
////	
////	char array[100], position, c, n;
////	
////		printf("Enter number of elements in array\n");
////		scanf("%c", &n);
////	
////		printf("Enter %d elements\n", n);
////	
////		for (c = 0; c < n; c++)
////			scanf("%d", &array[c]);
////	
////
////}
//
//
