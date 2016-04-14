#include <iostream>
#include <vector>

using namespace std;

void SMM(vector<vector<int>>, vector<vector<int>>, vector<vector<int>>&);

int main()
{

    vector<vector<int>> A = {   { 1, 2 },
                                { 3, 4 }    };
    vector<vector<int>> B = {   { 1, 2 },
                                { 3, 4 }    };
    vector<vector<int>> C = {   { 0, 0 },
                                { 0, 0 }    };;

    SMM(A, B, C);

    int n = C.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<C[i][j]<<"-";
        }
        cout<<endl;
    }

}

void SMM(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>>& C){
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
