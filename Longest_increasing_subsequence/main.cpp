#include <iostream>
#include <math.h>

using namespace std;

int* maxSubSeq(int, int[]);

int main() {

	int tam = 6;
	int A[tam] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int P[tam];
	int M[tam + 1];
	int len = 0, lo = 0, hi = len, mid = 0, nlen = 0;
	for (size_t i = 0; i <= tam - 1; ++i) {
		lo = 1;
		hi = len;
		while ( lo <= hi) {
			mid = ceil((lo+hi)/2);
			if (A[M[mid]] < A[i]) {
				lo = mid + 1;
			}
			else{
				hi = mid - 1;
			}
		}
		nlen = lo;
		P[i] = M[nlen - 1];
		M[nlen] = i;
		if (nlen > len) {
			len = nlen;
		}
	}
	int S[len];
	int k = M[len];
	for (int i = len - 1; i >= 0; --i) {
		S[i] = A[k];
		k = P[k];
	}
	for (size_t i = 0; i < len; ++i) {
		cout<<S[i]<<"-";
	}
	cout<<endl;
	cin>>tam;
}

int* maxSubSeq(int tam, int A[]){

	int P[tam];
	int M[tam + 1];
	int len = 0, lo = 0, hi = len, mid = 0, nlen = 0;

	for (size_t i = 0; i <= tam - 1; ++i) {
		lo = 1;
		hi = len;
		while ( lo <= hi) {
			mid = ceil((lo+hi)/2);
			if (A[M[mid]] < A[i]) {
				lo = mid + 1;
			}
			else{
				hi = mid - 1;
			}
		}
		nlen = lo;
		P[i] = M[nlen - 1];
		M[nlen] = i;
		if (nlen > len) {
			len = nlen;
		}
	}
	int S[len];
	int k = M[len];
	for (int i = len - 1; i >= 0; --i) {
		S[i] = A[k];
		k = P[k];
	}
	for (size_t i = 0; i < len; ++i) {
		cout<<S[i]<<"-";
	}
	cout<<endl;
};


/*
// C++ program to find length of longest increasing subsequence
// in O(n Log n) time
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])

// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int CeilIndex(int A[], int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (A[m]>=key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LongestIncreasingSubsequenceLength(int A[], int size)
{
    // Add boundary case, when array size is one

    int *tailTable   = new int[size];
    int len; // always points empty slot

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[0];
    len = 1;
    for (int i = 1; i < size; i++)
    {
        if (A[i] < tailTable[0])
            tailTable[0] = A[i];

        else if (A[i] > tailTable[len-1])
            tailTable[len++] = A[i];

        else
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }
	for (int i = 0; i < len; i++) {
		cout<<tailTable[i]<<"-";
	}
	cout<<endl;
    delete[] tailTable;
    return len;
}

int main()
{
    int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int n = ARRAY_SIZE(A);
    printf("Length of Longest Increasing Subsequence is %d\n",
           LongestIncreasingSubsequenceLength(A, n));
	cin>>n;
    return 0;
}*/
