#include <list>
#include <iostream>
#include <iterator>

using namespace std;

void bucket(double * array, int size);
void insertsort(double * arr, int size);


void bucket(double * array, int size)
{
	list<double> b[size];
	list<double>::iterator it;
	double * arr;
	int i = 0;
	int j = 0;
	int temp;
	
	for(i = 0; i < size; i++)
	{
		temp = size*array[i];
		b[temp].push_back(array[i]);
	}
	
	
	for(i = 0; i < size; i++)
	{
		it = b[i].begin();
		for(j = 0; j < b[i].size(); j++)
		{
			arr[j] = *it;
			it++;
		}
		
		insertsort(arr, b[i].size());
	}
	
}

void insertsort(double * arr, int size)
{
	int j = 0;
	int i = 0;
	double key;
	for (j = 1; j < size; j++)
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
	for(i = 0; i < size; i++)cout << arr[i] << endl;
}

int main()
{
	int size = -1;
	int i = 0;
	double * array;
	while(1)
	{
		scanf("%i", &size);
		if(size == 0)break;
		array = (double *)malloc(size * sizeof(double));
		
		for(i = 0; i < size; i++)
		{
			scanf("%lf", &array[i]);
		}	
		
		bucket(array, size);
	}
}
