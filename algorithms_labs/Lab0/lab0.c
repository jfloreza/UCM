
#include <stdio.h>


int test(int arr[], int length)
{
	int subindex, b, key1, key2, j;
	int i = 0;
	int check = 0;
	int e = 0;
	int arr2[length];
	
	
	while (i < length)
	{
		subindex = arr[i];
		if(subindex == 0)break;

		b = i + subindex;

		while(b != i)
		{
			if(b-1 != i) 
			{
				key1 = arr[b]; //Compare values
				key2 = arr[b-1];

				if(key2 > key1){printf("INCORRECT SEQUENCE\n"); check = 1; break;}
				else
					arr2[e] = key1; e++; //Move element to new array
			}
			
			if(b-1 == i)arr2[e] = arr[b]; //Takes care of last element
			b--;
		}
		i++;
		i = i+subindex;
		
		if(check == 0) //Means sequence did not fail test
		{
			for(j = 0; j < e+1; j++)
			{
				printf("%i\n", arr2[j]);
			}
		}
	}
}

int main(int argc, char* argv[]) 
{
  int is_sub_array = 0;
	int count = 0;
	int x, c;
	int i = 0;
	int j = 0;
	int arr[10];
	
	while(1)
	{
		scanf("%d", &c);
		if(c == 0 && is_sub_array == 0)break;
		is_sub_array = 1;
		arr[i] = c;
		i++;
		
		while (is_sub_array == 1)
		{
		  scanf("%d", &x);
		  arr[i] = x;
		  i++;
		  j++;
		  if(j == c)break;
		}
		j = 0;
		is_sub_array = 0;
	}	
	test(arr, i);
}
