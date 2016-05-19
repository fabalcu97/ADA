#include <tuple>

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int Recursive_CutRod(int p[], int n){
	if (n == 0){
		return 0;
	}
	int q = -1;
	for (int i = 0; i < n; ++i) {
		q = max(q, p[i] + Recursive_CutRod(p, n - i));
	}
	return q;
}


int TD_CutRod_Aux(int p[], int n, int r[]){
	if (r[n-1] >= 0) {
		return r[n-1];
	}
	int q = 0;
	if(n == 0){
		q = 0;
	}
	else{
		int q = -1;
		for (int i = 0; i < n; ++i) {
			q = max(q, p[i] + TD_CutRod_Aux(p, n - i, r));
		}
	}
	r[n-1] = q;
	return q;

}
int TD_CutRod(int p[], int n){
	int r[n];
	for (int i = 0; i < n; ++i) {
		r[i] = -1;
	}
	return TD_CutRod_Aux(p, n, r);
}

int BU_CutRod(int p[], int n){
	int r[n];
	r[0] = 0;
	int q = 0;
	for (int i = 0; i < n; ++i) {
		q = -1;
		for (int j = 0; j < i; ++j) {
			q = max(q, p[j] + r[i-j]);
		}
		r[i] = q;
	}
	return r[n-1];
}

std::tuple<int*, int*> EBU_CutRod(int p[], int n){
	int r[n], s[n];
	r[0] = 0;
	int q = 0;
	for (int i = 0; i < n; ++i) {
		q = -1;
		for (int j = 0; j < i; ++j) {
			if ( q < p[j] + r[i-j]) {
				q = p[j] + r[i-j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
	std::tuple<int*, int*> res(r, s);
	return res;
}
