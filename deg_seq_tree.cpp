#include <iostream>
using namespace std;
int ** deg_seq_tree(int * ds, int n);
bool check(int * ds);
void print_matrix(int ** m, int n);

int main()
{
	int n;
	cout << "Order of Tree: ";
	cin >> n;
	int * ds = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout << "Degree of vertex " << i+1 << " : ";
		cin >> ds[i];
	}
	int ** m = deg_seq_tree(ds, n);
	print_matrix(m, n);
}

// construct a tree with given degree sequence
// return an adjacency matrix
int ** deg_seq_tree(int * ds, int n)
{
	int i,j,k;
	// create a matrix of size n by n, and set all entries to zero
	int ** result = new int *[n];
	for(i = 0; i < n; i++)
		result[i] = new int[n];
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			result[i][j] = 0;
		}

	if(n == 1)
	{
		return result;
	}
	//find the largest index have value different from 1
	for(i = 0; i < n; i++)
		if(ds[i] == 1)
		{
			i = i -1;
			if(i < 0)
				i = 0;
			break;
		}
	// create temp consists degree sequence of subgraph of order n-1
	int * temp = new int[n-1];
	for(j = 0; j < n-1; j++)
	{
		if(j != i)
			temp[j] = ds[j];
		else
			temp[j] = ds[j]-1;
	}
	int ** dps = deg_seq_tree(temp, n-1);
	for(j = 0; j < n-1; j++)
		for(k = 0; k < n-1; k++)
			result[j][k] = dps[j][k];
	result[n-1][i] = 1; result[i][n-1] =1;
	return result;
}


bool check(int * ds)
{
	int n = sizeof(ds)/sizeof(*ds);	
	int i, sum = 0;
	for(i = 0; i < n-1; i++)
		if( ds[i] <= 0 || ds[i] < ds[i+1])
		{
			cout << "Not A Degree Sequence";
			return false;
		}
	
	for(i = 0; i < n; i++)
		sum += ds[i];
	if( sum != 2*(n-1))
	{
		cout << "Cannot Construct Tree!";
		return false;	
	}
	return true;
}

void print_matrix(int ** m, int n)
{
	int i; int j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			std::cout << m[i][j];
		std::cout << "\n";
	}
}



