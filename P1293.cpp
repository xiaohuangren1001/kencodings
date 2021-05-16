#include <iostream>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	cout << ((a % 10000) * (b % 10000)) % 10000;
	return 0;
}
