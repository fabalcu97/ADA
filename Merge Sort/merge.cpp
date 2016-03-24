#include <iostream>

using namespace std;

int big(int lista[], int length)
{
	int tmp = lista[0];
	for (int i = 0; i < length; i++) {
		if (lista[i] > tmp)
		{
			tmp = lista[i];
		}
	}
	return tmp + 1;
}

void merge(int *lista, int idx_i, int idx_m, int idx_f)
{
	/*cout<<"p: "<<idx_i<<" q: "<<idx_m<<" r: "<<idx_f<<endl;*/

	int n1 = idx_m - idx_i + 1;
	int n2 = idx_f - idx_m;

	int L[n1 + 1];
	int R[n2 + 1];

	int tmp = /*big(lista, idx_f-1)*/ 100000;
	L[n1] = tmp;
	R[n2] = tmp;

	for (int i = 0; i < n1; i++)
	{
		L[i] = lista[ idx_i + i ];
	}

	for (int i = 0; i < n2; i++)
	{
		R[i] = lista[ idx_m + 1 + i ];
	}
	/*cout<<"L: ";
	for (int i = 0; i < n1+1; i++) {
		cout<<L[i]<<"-";
	}
	cout<<"\nR: ";
	for (int i = 0; i < n2+1; i++) {
		cout<<R[i]<<"-";
	}
	cout<<endl;*/
	int	i = 0,
		j = 0;

	for (int k = idx_i; k <= idx_f; k++)
	{
		if ( L[i] <= R[j] )
		{
			lista[k] = L[i];
			i++;
		}
		else
		{
			lista[k] = R[j];
			j++;
		}
	}
}
