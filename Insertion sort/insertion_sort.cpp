#include <iostream>

using namespace std;

int main(){
    int len = 6;

    cout<<"Ingrese el tamaño de a lista: ";
    cin>>len;

    int A[len];// = {31, 41, 59, 26, 41, 58};
    int key = 0;
    int j = 0;

    for (int i = 0; i < len; i++){
        cout<<"Ingrese el elemento numero "<<i+1<<" : ";
        cin>>A[i];
    }

    for (int i = 1; i < len; i++){
        key = A[i];
        j = i - 1;

        while( j > -1 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    for (int i = 0; i < len; i++){
        cout<<A[i]<<"-";
    }


}
