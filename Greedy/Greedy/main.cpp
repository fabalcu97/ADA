#include <iostream>
#include <vector>

using namespace std;

vector<int> recur_AC(vector<int>*, int[], int[], int, int);
vector<int> iter_AC(vector<int>*, int[], int[], int);


int main()
{
    int k = -1;
    int n = 11;

    vector<int> Res;

    int s[n] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[n] = {3, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    recur_AC(&Res, s, f, k, n);
    cout<<"Recursivo: ";
    for(int i = 0; i < Res.size(); ++i){
        cout<<Res[i]<<"-";
    }
    cout<<endl<<endl;
    Res.clear();
    iter_AC(&Res, s, f, n);
    cout<<"Iterativo: ";
    for(int i = 0; i < Res.size(); ++i){
        cout<<Res[i]<<"-";
    }
    cout<<endl;

}


vector<int> recur_AC(vector<int>* Res, int S[], int F[], int k, int n){

    int m = k + 1;

    while(m < n && k > (-1) && S[m] < F[k]){
        ++m;
    }
    if(m < n){
        Res->push_back(S[m]);
        cout<<"Activity "<<m+1<<": "<<S[m]<<endl;
        recur_AC(Res, S, F, m, n);
        return *Res;
    }
    return *Res;
}

vector<int> iter_AC(vector<int>* Res, int S[], int F[], int n){

    Res->push_back(S[0]);

    int k = 0;

    for(int i = 1; i < n; ++i){
        if(S[i] >= F[k]){
            Res->push_back(S[i]);
            k = i;
        }
    }
    return *Res;
}
