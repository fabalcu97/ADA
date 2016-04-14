#include <iostream>
#include <vector>

using namespace std;

void SMMR(vector<vector<int>>, vector<vector<int>>, vector<vector<int>>&);

int main()
{

    vector<vector<int>> A = {   { 1, 2 },
                                { 3, 4 }    };
    vector<vector<int>> B = {   { 1, 2 },
                                { 3, 4 }    };
    vector<vector<int>> C = {   { 0, 0 },
                                { 0, 0 }    };;

    SMMR(A, B, C);

    int n = C.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<C[i][j]<<"-";
        }
        cout<<endl;
    }

}

void SMMR(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>>& C){
    int n = A.size();
    if (n == 0){
        C[0][0] = A[0][0] * B[0][0];
    }
    else{
        C[0][0] =  SMMR(A[0][0], B[0][0], C) + SMMR(A[0][1], B[0][1], C);
        C[0][1] =  SMMR(A[0][0], B[0][1], C) + SMMR(A[0][1], B[1][1], C);
        C[1][0] =  SMMR(A[1][0], B[0][0], C) + SMMR(A[1][1], B[1][0], C);
        C[1][1] =  SMMR(A[1][0], B[0][1], C) + SMMR(A[1][1], B[1][1], C);
    }
}
