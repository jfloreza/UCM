#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int hash_insert(list<int> *hash_table, int k, int m)
{
	int j = k % m;
	hash_table[j].push_front(k);
}

void hash_print(list<int> *hash_table, int m)
{
	int i = 0;
	int j = 0;
	list<int>::iterator it;
	
	for(i = 0; i < m; i++)
	{
		it = hash_table[i].begin();
		for(j = 0; j < hash_table[i].size(); j++)
		{
			cout << *it << "->";
			it++;
		}
	}
	
	cout << endl;
}

int hash_search(list<int> *hash_table, int k, int m)
{
	int i = 0;
	int j;
	int temp;
	
	list<int>::iterator it;
	
	j = k % m;
	it = hash_table[j].begin();
	for(i = 0; i < hash_table[j].size(); i++)
	{
		if(*it == k){cout << j << "," << i << endl;return 0;}
		it++;
	}

	cout << "NOT_FOUND" << endl;
	
	
}

void hash_delete(list<int> *hash_table, int k, int m)
{
	int j = k % m;	
	hash_table[j].remove(k);
}


int main()
{
	int i = 0;
	int hash_size = 0;
	int temp;
	int * arr;
	
	arr = (int *)malloc(sizeof(int));
	
	cin >> hash_size;
	list<int> hash_table[hash_size];
	
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
	}
	
	while(1)
	{
		cin >> temp;
		if(temp == -3)break;
		hash_delete(hash_table, temp, hash_size);
	}
	
	hash_print(hash_table, hash_size);
}
