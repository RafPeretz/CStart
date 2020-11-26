#include <stdio.h>
#include<stdlib.h>


int is_contains(int *arr, int size, int el)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == el)
			return 1;
	}
	return 0;
}

int *filter_multiple(int arr[], int size)
{
	int count = 0;
	int *new_arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = 0;
	}

	int idx = 0;

	for (int i = 0; i < size; i++)
	{
		if (is_contains(new_arr, size, arr[i]) == 0)
		{
			new_arr[idx] = arr[i];
			idx++;
		}
		//efface
		count = 0;
	}
	return new_arr;

}

int main()
{
	int array[10] = { 1,1,2,2,3,3 , 4,5,6 };
	int n = 9;
	int c = 0;
	int* p;

	p = filter_multiple(array, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	getchar();
}