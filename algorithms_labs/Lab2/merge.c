#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int merge_sort(int * arr, int p, int r)
{
	int q = (p+r)/2;
	if (p < r)
	{
		
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
	
	
}

int merge(int * arr, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int i, j, k;
	
	int * left = (int *)malloc(sizeof(int)*(n1+1));
	int * right = (int *)malloc(sizeof(int)*(n2+1));
	
	for (i = 0; i < n1; i++)
	{
		left[i] = arr[p+i];
	}
	
	for (j = 0; j < n2; j++)
	{
		right[j] = arr[q+j];
	}
	
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	i = 0; 
	j = 0;

	for (k = p; k < r; k++ )
	{

		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
	}
	
}

int main(int argc, char* argv[])
{	
	int size = -1;
	int val;
	int i = 0;
	int * array;
	double time1, time2;
	while(1)
	{
		scanf("%i", &size);
		if(size == 0)break;

		array = (int *)malloc(size * sizeof(int));
		
		for(i = 0; i < size; i++)
		{
			scanf("%i", &array[i]);
		}
		
	val = merge_sort(array, 0, size-1);
	
	for (i = 0; i < size; i++)
	{
		printf("%i\n", array[i]);
	}
	
	free(array);
	}
}
