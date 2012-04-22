#include <stdio.h>
#include <stdlib.h>


int sort(int arr[], int n)
{
	int j = 0;
	int i = 0;
	int key;
	for (j = 1; j < n; j++)
	{
		key = arr[j];
		i = j - 1;
		
		while(i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		
		arr[i+1] = key;
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
		
		val = sort(array, size);
	
		for (i = 0; i < size; i++)
		{
			printf("%i\n", array[i]);
		}
	}
	
	
	
	free(array);
}
