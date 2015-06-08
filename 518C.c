#include <stdio.h>

int Screen[100000];
int A[100000];

int main()
{
    int N, M, K, i, Num;
    long long Ans;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        Screen[A[i]] = i;
    }
    for(Ans = i = 0; i < M; ++i) {
        scanf("%d", &Num);
        Ans += Screen[Num] / K + 1;
        if(Screen[Num] != 0) {
            int changenum = A[Screen[Num] - 1];
            int nowpos = Screen[Num];
            A[nowpos] = changenum;
            A[nowpos - 1] = Num;
            --Screen[Num];
            ++Screen[changenum];
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
