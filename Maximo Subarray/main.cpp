#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void max_subarray(vector<int>, int, int);
void max_crossing_subarray(vector<int>, int, int, int);
int smaller(vector<int>);

struct C_Res{
	int M_left = 0;
	int M_right = 0;
	int Sum = 0;
};

struct M_Res{
	int A = 0;
	int low = 0;
	int high = 0;
};

C_Res Cross_SA;
M_Res Max_SA;

int main(){

	vector<int> A = {
					13, -3, -25,
					20, -3, -16,
					-23, 18, 20,
					-7, 12, -5,
					-22, 15, -4,
					7};
	max_subarray(A, 0, A.size());
	cout<<Max_SA.high<<endl;
	cout<<Max_SA.low<<endl;
	cout<<Max_SA.A<<endl;
}

int smaller(vector<int> A){
	int tmp = A[0];
	for (int i = 0; i < A.size(); i++) {
		if (A[i] < tmp){
			tmp = A[i];
		}
	}
	return tmp - 1;
}

void max_crossing_subarray(vector<int> A, int low, int mid, int high){
	int l_sum,
		sum = 0,
		m_left = 0,
		r_sum = 0,
		m_right = 0;

	l_sum = smaller(A);

	for (int i = mid; i >= low; i--) {
		sum += A[i];
		if (sum > l_sum) {
			l_sum = sum;
			m_left = i;
		}
	}

	r_sum = smaller(A);
	sum = 0;
	for (int i = mid + 1; i < high; i++) {
		sum += A[i];
		if (sum > r_sum) {
			r_sum = sum;
			m_right = i;
		}
	}
	Cross_SA.M_left = m_left;
	Cross_SA.M_right = m_right;
	Cross_SA.Sum = l_sum + r_sum;
}

void max_subarray(vector<int> A, int low, int high){
	if(high == low){
		Max_SA.low = low;
		Max_SA.high = high;
		Max_SA.A = A[low];
		return;
	}
	else{
		int mid = floor((low + high) / 2);
		int ll = 0, lh = 0, ls = 0,
			rl = 0, rh = 0, rs = 0,
			cl = 0, ch = 0, cs = 0;

		max_subarray(A, low, mid);
		ll = Max_SA.low;
		lh = Max_SA.high;
		ls = Max_SA.A;
		max_subarray(A, mid + 1, high);
		rl = Max_SA.low;
		rh = Max_SA.high;
		rs = Max_SA.A;
		max_crossing_subarray(A, low, mid, high);
		cl = Cross_SA.M_left;
		ch = Cross_SA.M_right;
		cs = Cross_SA.Sum;
		if (ls >= rs && ls >= cs) {
			Max_SA.low = ll;
			Max_SA.high = lh;
			Max_SA.A = ls;
			return;
		}
		else if (rs >= ls && rs >= cs) {
			Max_SA.low = rl;
			Max_SA.high = rh;
			Max_SA.A = rs;
			return;
		}
		Max_SA.low = cl;
		Max_SA.high = ch;
		Max_SA.A = cs;
		return;
	}

}
