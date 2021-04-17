#include <bits/stdc++.h>
using namespace std;
vector<char> str;
int n, x;
#define IT vector<char>::iterator
IT iter;
void getiter(vector<char> &s, int i) {
    iter = s.begin();
    for (int j = 0; j < i; j++) {
        iter++;
    }
}
void ins(vector<char> &s, int i, char c) {
    getiter(s, i);
    s.insert(iter, c);
}
void del(vector<char> &s, int i) {
    getiter(s, i);
    s.erase(iter);
}
void sort(vector<char> &s) {
    sort(s.begin(), s.end());
}
void outvec(vector<char> &s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
}
vector<string> split(string str) {
    vector<string> res;
    stringstream ss(str);
    string word;
    while (ss >> word) res.push_back(word);
    return res;
}
bool startwith(string s, string sub) {
    return s.find(sub) == 0;
}
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        str.push_back(ch);
    }
    for (int i = 0; i < x; i++) {
        string s;
        getline(cin, s);
        getline(cin, s);
        if (startwith(s, string("I"))) {
            vector<string> ss = split(s);
            string x = ss[1];
            string c = ss[2];
            stringstream sss(x);
            int ix;
            sss >> ix;
            char ch = c[0];
            ins(str, ix, ch);
        } else if (startwith(s, string("D"))) {
        	vector<string> ss = split(s);
            string x = ss[1];
            stringstream sss(x);
            int ix;
            sss >> ix;
            del(str, ix);
        }
    }
    sort(str);
    outvec(str);
    return 0;
}
