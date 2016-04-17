#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, c, a, b, sum, i;
    int p[50], t[50];
    scanf("%d %d", &n, &c);
    for(i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    for(i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    a = sum = 0;
    for(i = 0; i < n; ++i) {
        sum += t[i];
        a += max(0, p[i] - c * sum);
    }
    b = sum = 0;
    for(i = n - 1; i >= 0; --i) {
        sum += t[i];
        b += max(0, p[i] - c * sum);
    }
    if(a > b) {
        puts("Limak");
    } else if(a < b) {
        puts("Radewoosh");
    } else {
        puts("Tie");
    }
    return 0;
}
