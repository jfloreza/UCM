#include <stdio.h>
#include <stdlib.h>


void counting(int * a, int * b, int size)
{
	int i, j, ksize;
	int k = -100;
	int * c;
	
	for(i = 0; i < size; i++)
	{
		if(a[i] >= k)
		{
			k = a[i];
		}
	}
	
	c = (int *)malloc((k + 1) * sizeof(int));
	
}


int main(int argc, char* argv[])
{	
	int size = -1;
	int val;
	int i = 0;
	int * array;
	int * arrayb;
	while(1)
	{
		scanf("%i", &size);
		if(size == 0)break;
		array = (int *)malloc(size * sizeof(int));
		arrayb = (int *)malloc(size * sizeof(int));
		
		for(i = 0; i < size; i++)
		{
			scanf("%i", &array[i]);
		}	
		
		counting(array, arrayb, i);
	
		for (i = 0; i < size; i++)
		{
			printf("%i\n", arrayb[i]);
		}
	}
	
	free(array);
}
