#include <iostream>

using namespace std;

void max_heapify(int*, int, int);
void heapsort(int*, int);
void build_max_heap(int*);

int main()
{
    int n = 10;
    int heap[10] = { 4, 1, 3, 2, 0, 9, 10, 14, 8, 7 };
    srand(time(NULL));

    cout<<"Elementos: \n   ";
    for(int i = 0; i < n; i++){
        cout<<heap[i]<<"-";
    }
    heapsort(heap, n);
    cout<<"\n\n\nOrdenado: \n   ";
    for(int i = 0; i < n; i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;

}

void max_heapify(int *A, int index, int length){

    int tmp = 0;
    int largest = index;
    int left = 2 * index;
    int right = (2 * index) + 1;

    if ( left < length && A[left] > A[index] ){
        largest = left;
    }
    if ( right < length && A[right] > A[largest] ){
        largest = right;
    }
    if ( largest != index ){
        tmp = A[index];
        A[index] = A[largest];
        A[largest] = tmp;
        max_heapify(A, largest, length);
    }
}

void build_max_heap(int *A, int length){

    for (int i = length/2; i >= 0; i--){
        max_heapify(A, i, length);
    }

}

void heapsort(int *A, int n){

    build_max_heap(A, n);
    int tmp = 0;

    for(int i = n-1; i >= 1; i--){
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        n--;
        max_heapify(A, 0, n);
    }
}


