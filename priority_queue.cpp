#include <iostream>
#include <vector>

using namespace std;

vector<int> max_heapify(int, int, int);
vector<int> heapsort(int, int);
vector<int> build_max_heap(int);
int MHeap_extract(vector<int>&, int);
void Increase_key(vector<int>&, int, int);
void MHeap_insert(vector<int>&, int, int);

int main()
{
    vector<int> heap;


    MHeap_insert(heap, 9, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_insert(heap, 10, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_insert(heap, 11, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_insert(heap, 12, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_extract(heap, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_extract(heap, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_extract(heap, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;
    MHeap_extract(heap, heap.size());
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<"-";
    }
    cout<<endl;

}

vector<int> max_heapify(vector<int> &A, int index, int length){

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
//        tmp = A[index];
//        A[index] = A[largest];
//        A[largest] = tmp;
        swap(A[index], A[largest]);
        max_heapify(A, largest, length);
    }
}

vector<int> build_max_heap(vector<int> &A, int length){

    for (int i = length/2; i >= 0; i--){
        max_heapify(A, i, length);
    }

}

vector<int> heapsort(vector<int> &A, int n){

    build_max_heap(A, n);
    int tmp = 0;

    for(int i = n-1; i >= 1; i--){
//        tmp = A[i];
//        A[i] = A[0];
//        A[0] = tmp;
        swap(A[i], A[0]);
        n--;
        max_heapify(A, 0, n);
    }
}

int MHeap_extract(vector<int> &A, int n){
    if(n < 0){
        cout<<"\nError\n";
        return 0;
    }
    int maximo = A[0];
    A[0] = A[n-1];
    A.erase(A.begin());
    n--;
    max_heapify(A, 0, n);
    return maximo;
}

void Increase_key(vector<int> &A, int index, int key){
    if(A.size() < 0){
        cout<<"\nError\n";
        return;
    }
    A[index] = key;
    while( index > 0 && A[index/2] < A[index]){
        swap(A[index], A[index/2]);
        index = index/2;

    }
}

void MHeap_insert(vector<int> &A, int key, int n){
    n++;
    A.push_back(-100000);
    Increase_key(A, n, key);
}









