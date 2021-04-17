#include <iostream>
#define MAXN 10010
using namespace std;
int d[MAXN], len;
void InsertionSort(int V[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        if (V[i] < V[i-1]) {
            V[0] = V[i];
            for (j = i - 1; V[0] < V[j]; j--) V[j+1]=V[j];
            V[j+1] = V[0];
        }
    }
}
int main() {
    int i, len;
    cin >> len;
    for (i = 1; i <= len; i++) cin >> d[i];
    InsertionSort(d, len);
    for (i = 1; i <= len; i++) cout << d[i] << ' ';
    cout << endl;
    return 0;
}
