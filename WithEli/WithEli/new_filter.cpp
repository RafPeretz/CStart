#include <stdio.h>
#include<stdlib.h>


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
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}

		if (count == 1)
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
	int array[100], position, c, n;
	int *p;


	printf("Enter the size of the array you want \n");
	scanf("%d", &n);
	printf("Enter %d elements\n", n);
	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);
	p = filter_multiple(array, n);
	getchar();
	free(array);


}