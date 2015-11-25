#include <stdio.h>

long long Fun()
{
    int i, len, b, x;
    long long ret = 0;
    scanf("%d %d", &len, &b);
    for(i = 0; i < len; ++i) {
        ret *= b;
        scanf("%d", &x);
        ret += x;
    }
    return ret;
}

int main()
{
    long long A = Fun();
    long long B = Fun();
    if(A == B) {
        puts("=");
    } else if(A < B) {
        puts("<");
    } else {
        puts(">");
    }
    return 0;
}
