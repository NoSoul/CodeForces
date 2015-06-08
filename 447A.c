#include <stdio.h>

int Hash[300];

int H(int x, int p)
{
    return x % p;
}

int main()
{
    int P, N, i, Ans = -1, Num;
    scanf("%d %d", &P, &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        if(Hash[H(Num, P)]) {
            Ans = i + 1;
            break;
        }
        Hash[H(Num, P)] = 1;
    }
    printf("%d\n", Ans);
    return 0;
}
