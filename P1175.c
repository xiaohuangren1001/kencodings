#include <stdio.h>
main()
{
    int tot = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) {
        int t = n;
        n = m;
        m = t;
    }
    for (int i = n; i <= m; i++) {
        if (i % 2 == 0) tot += i;
    }
    printf("%d", tot);
    return 0;
}
