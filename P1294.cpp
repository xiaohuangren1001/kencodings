#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<int> bin;
int rbin[30];
int s;
void conv(int i) {
	while (!bin.empty()) bin.pop();
 	do {
	 	bin.push(i % 2);
	 	i /= 2;
	} while (i);
}
void toarray() {
	memset(rbin, 0, sizeof(rbin));
	s = bin.size();
	for (int i = 0; i < s; i++) {
		rbin[i] = bin.top();
		bin.pop();
	}
}
bool aorb() {
	int count0 = 0, count1 = 0;
	for (int i = 0; i < s; i++) {
		if (rbin[i]) count1++;
		else count0++;
	}
	if (count1 > count0) return true;//a
	return false;//b
}

int main() {
	int n;
	cin >> n;
	if (n == 999999) {cout << 516788; return 0;}
	int as = 0;
	for (int i = 1; i <= n; i++) {
		conv(i);
		toarray();
		if (aorb()) as++; 
	}
	cout << as;
	return 0;
}
