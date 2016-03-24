#include <iostream>

using namespace std;

int* insertion_order(int[], int);

int main(){
    int len = 6;

    cout<<"Ingrese el tamaño de a lista: ";
    cin>>len;

    int A[len];

    for (int i = 0; i < len; i++){
        cout<<"Ingrese el elemento numero "<<i+1<<" : ";
        cin>>A[i];
    }

	insertion_order(A, len);

    for (int i = 0; i < len; i++){
        cout<<A[i]<<"-";
    }


}

int* insertion_order(int A[], int length){

	int key = 0;
    int j = 0;

	for (int i = 1; i < length; i++){
        key = A[i];
        j = i - 1;

        while( j > -1 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
	return A;
}
