#include <iostream>
#include <stack>
using namespace std;
stack<int> res;
void convert(int n, int d) {
    while (n) {
        res.push(n % d);
        n /= d;
    }
}
void out() {
    while (!res.empty()) {
        int t = res.top();
        res.pop();
        cout << t << " ";
    }
}
int main() {
    int n, d;
    cin >> n >> d;
    convert(n, d);
    out();
    return 0;
}
