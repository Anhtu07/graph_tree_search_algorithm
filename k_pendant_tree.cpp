#include <iostream>
using namespace std;
int ** k_pendant_tree(int n, int k);
int **mt(int n, int **m);
void print_matrix(int ** m, int n);

int main()
{
	int n; int k;
	cout << "Order of tree: ";
	cin >> n;
	cout << "Number of leaves: ";
	cin >> k;
	int ** matrix;
	matrix = k_pendant_tree(n, k);
	print_matrix(matrix, n);
	return 0;
}

// construct a tree of order n with k pendants
// return an adjacency matrix
int ** k_pendant_tree(int n, int k)
{
	//create empty n by n matrix
	int ** m = new int *[n];
	for(int i = 0; i < n; i++)
		m[i] = new int[n];
	
	//fill matrix with 0
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			m[i][j] = 0;
	
	//consider node 0 as root, add k-1 leaves to node 0
	for(int i = n-1; i > n-k; i--)
		m[0][i] = 1;
	
	//extend one edge
	for(int i = 0; i < n-k; i++)
		m[i][i+1] = 1;
	
	m = mt(n, m);
	return m;
}

//m = m + m^T
int **mt(int n, int **m)
{
	int i; int j;
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			m[i][j] = m[j][i];
	return m;
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
