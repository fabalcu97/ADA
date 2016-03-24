#include <iostream>
#include <math.h>
#include "merge.h"

using namespace std;

void merge_sort(int*, int, int);

int main()
{

	int n = 0;
	cout<<"Tamaño: ";
	cin>>n;

	int lista[n];

	cout<<"Inserte elementos de la lista: ";

	for(int	i = 0; i < n; i++){
		cin>>lista[i];
	}

	for (int i = 0; i < n; i++) {
		cout<<lista[i]<<"-";
	}
	cout<<endl;

	merge_sort(lista, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout<<lista[i]<<"-";
	}
	cout<<endl;
}

void merge_sort(int *lista, int idx_i, int idx_f)
{
	if ( idx_i < idx_f ) {
		int q = (( idx_i + idx_f ) / 2);
		merge_sort(lista, idx_i, q);
		merge_sort(lista, q + 1, idx_f);
		merge(lista, idx_i, q, idx_f);
	}
}
