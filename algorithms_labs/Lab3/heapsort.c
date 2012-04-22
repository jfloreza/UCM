#include <stdio.h>
#include <stdlib.h>

int heapsort(int * arr, int size)
{
	int i, j, temp;
	buildheap(arr, size);
	
	for(i = size - 1; i > 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		
		heapify(arr, 0, i);
	}
		
}

int buildheap(int * arr, int size)
{
	int i;
	for(i = (size/2)-1; i >= 0; i--)
	{
		heapify(arr, i, size);
	}
}

int heapify(int * arr, int i, int size)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest, temp;
	int j;
	
	if(left <= size-1 && arr[left] > arr[i])
	{
		largest = left;
	} else {
		largest = i;
	}
	
	if(right <= size-1 && arr[right] > arr[largest])
	{
		largest = right;
	}
	
	if(i != largest)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, largest, size);
	}
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
		
		heapsort(array, size);
	
		for (i = 0; i < size; i++)
		{
			printf("%i\n", array[i]);
		}
	}
	
	free(array);
}
