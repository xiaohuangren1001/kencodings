#include <bits/stdc++.h>
using namespace std;
struct tangsanshuzi {
private:
	enum LIMITS {A='a',B,C,D,E,F,G,H,I,J};
	static const int SIZE = 5;
	char numbers[10];
public:
	tangsanshuzi(string s);
	bool operator<(tangsanshuzi & another);
	bool operator==(tangsanshuzi & another);
	friend tangsanshuzi plusone(tangsanshuzi s);
	friend ostream & operator<<(ostream & os, const tangsanshuzi & tssz);
};
tangsanshuzi::tangsanshuzi(string s)
{
	if (s.size() != SIZE) cout << "ERR";
	else {
		for (int i = 0; i < SIZE; i++) {
			if (s[i] != A && s[i] != B && s[i] != C && s[i] != D && s[i] != E && s[i] != F && s[i] != G && s[i] != H && s[i] != I && s[i] != J) {
				cout << "ERR";
				break;
			}
			numbers[i] = s[i];
		}
	}
}
bool tangsanshuzi::operator<(tangsanshuzi & another)
{
	if (strcmp(numbers, another.numbers) >= 0) return false;
	return true;
}
bool tangsanshuzi::operator==(tangsanshuzi & another)
{
	if (strcmp(numbers, another.numbers) == 0) return true;
	return false;
}
tangsanshuzi plusone(tangsanshuzi s) {
	if (s.numbers[tangsanshuzi::SIZE - 1] != tangsanshuzi::J) {
		s.numbers[tangsanshuzi::SIZE - 1]++;
		return s;
	} else {
		s.numbers[tangsanshuzi::SIZE - 2]++;
		if (s.numbers[tangsanshuzi::SIZE - 2] != tangsanshuzi::J)
			return s;
		else {
			s.numbers[tangsanshuzi::SIZE - 3]++;
			s.numbers[tangsanshuzi::SIZE - 2]--;
			return s;
		}
	}
}
ostream & operator<<(ostream & os, const tangsanshuzi & tssz) {
	os << tssz.numbers;
	return os;
}
int main()
{
	int a, b, c; cin >> a >> b >> c;
	string s; cin >> s;
	tangsanshuzi tssz(s);
	tangsanshuzi add1 = plusone(tssz);
	tangsanshuzi add2 = plusone(add1);
	tangsanshuzi add3 = plusone(add2);
	tangsanshuzi add4 = plusone(add3);
	tangsanshuzi add5 = plusone(add4);
	cout << add1 << endl << add2 << endl << add3 << endl << add4 << endl;
	return 0;
}
