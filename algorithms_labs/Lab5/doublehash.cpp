#include <iostream>

using namespace std;

int hash_insert(int * hash_table, int k, int m)
{
	int i = 0;
	int j;
	for(i = 0; i < m; i++)
	{
		j = ((k % m) + i*(1 + k % 11)) % m;
		
		if((hash_table[j] == -1) || (hash_table[j] == -2))
		{
			hash_table[j] = k;
			return j;
		} 
	}
		
	cout << "Hash table overflow" << endl;	
}

void hash_print(int * hash_table, int m)
{
	int i = 0;
	for(i = 0; i < m; i++)
	{
		if((hash_table[i] == -1) || (hash_table[i] == -2))
		{
			cout << endl;
		} else 
			cout << hash_table[i] << endl;
	}
}

int hash_search(int * hash_table, int k, int m)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		j = ((k % m) + i*(1 + k % 11)) % m;
		if (hash_table[j] == k)
		{
			cout << j << endl;
			return 0;
		}
	}
	
	cout << "NOT_FOUND" << endl;
}

void hash_delete(int * hash_table, int k, int m)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		j = ((k % m) + i*(1 + k % 11)) % m;
		if(hash_table[j] == k)
		{
			hash_table[j] = -2;
		}
	}
}

void print_array(int * array, int m)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(array[i] == 0)
		{
			cout << "NOT_FOUND" << endl;
		} else
			cout << array[i] << endl;
	}
}


int main()
{
	int i = 0;
	int hash_size = 13;
	int temp;
	int * search_array;
	int hash_table[13];
	
	search_array = (int *)malloc(sizeof(int));
	
	for(i = 0; i < 13; i++)
	{
		hash_table[i] = -1;
	}
	
	i = 0;
	
	while(1)
	{
		cin >> temp;
		if(temp == -1)break;
		hash_insert(hash_table, temp, hash_size);	
	}
	
	hash_print(hash_table, hash_size);
	
	while(1)
	{
		cin >> temp;
		if(temp == -2)break;
		hash_search(hash_table, temp, hash_size);
		
		//search_array[i] = hash_search(hash_table, temp, hash_size);
		//i++;
	}
	//print_array(search_array, i);	
	
	while(1)
	{
		cin >> temp;
		if(temp == -3)break;
		hash_delete(hash_table, temp, hash_size);
	}
	

	hash_print(hash_table, hash_size);
}
