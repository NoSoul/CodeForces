#include <stdio.h>

char Hash[100000];

int main()
{
    int A, M;
    scanf("%d %d", &A, &M);
    while(1) {
        int p = A % M;
        if(p == 0) {
            puts("Yes");
            return 0;
        }
        if(Hash[p]) {
            puts("No");
            return 0;
        }
        Hash[p] = 1;
        A += p;
        A %= M;
    }
    return 0;
}
