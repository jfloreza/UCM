#include <stdlib.h>
#include <stdio.h>

int quicksort(int * arr, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = partition(arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}

int partition(int * arr, int p, int r)
{
	int x = arr[r];
	int i = p-1;
	int j = 0; 
	int temp;
	for(j = p; j < r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			
		}
	}
	
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	
	return i+1;
}

int main(int argc, char* argv[])
{	
	int size = -1;
	int val;
	int i = 0;
	int * array;
	while(1)
	{
		scanf("%i", &size);
		if(size == 0)break;
		array = (int *)malloc(size * sizeof(int));
		
		for(i = 0; i < size; i++)
		{
			scanf("%i", &array[i]);
		}	
		
		quicksort(array, 0, size-1);
	
		for (i = 0; i < size; i++)
		{
			printf("%i\n", array[i]);
		}
	}
	
	free(array);
}
