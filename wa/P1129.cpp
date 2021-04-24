#include <stdio.h>
#define ui unsigned int
#define MAXN 500005
inline ui read()
{
    ui s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}
ui n, d, k, tot;
ui x[MAXN], s[MAXN];
int main()
{
    n = read(), d = read(), k = read();
    for (int i = 0; i < n; i++) {
        x[i] = read(); s[i] = read();
    }
    for (int i = 0; i < n; i++) {
        if (s[i] > 0) tot += s[i];
    }
    if (tot < k) puts("-1");
}
