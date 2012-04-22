#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int bin(int * array, int size, int search)
{
	int l = 0;
	int r = size;
	int m;
	
	while (l <= r)
	{
		m = (r + l) / 2;
		if(array[m] == search)return m;
		else if (array[m] > search)
		{
			r = m - 1;
		}
		else l = m + 1;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	struct timeval T;
	
	int size = -1;
	int val;
	int search;
	int i = 0;
	int * array;
	double time1, time2;
	while(1)
	{
		scanf("%i", &size);
		if(size == 0)break;
		
		scanf("%i", &search);
		array = (int *)malloc(size * sizeof(int));
		
		for(i = 0; i < size; i++)
		{
			scanf("%i", &array[i]);
		}
		
	gettimeofday(&T, NULL);
	time1 = T.tv_sec+(T.tv_usec/1000000.0);
	val = bin(array, size, search);
	gettimeofday(&T, NULL);
	time2 = T.tv_sec+(T.tv_usec/1000000.0);
	
	printf("%i\n", val);
	printf("Time is: %.6lf seconds\n", time2-time1);
	free(array);
	}

}
