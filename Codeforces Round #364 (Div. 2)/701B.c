#include <stdio.h>

char Row[100001];
char Col[100001];
int RowCnt, ColCnt;

int main()
{
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    while(M--) {
        scanf("%d %d", &x, &y);
        if(!Row[x]) {
            Row[x] = 1;
            ++RowCnt;
        }
        if(!Col[y]) {
            Col[y] = 1;
            ++ColCnt;
        }
        printf("%I64d ", (long long)N * N - (long long)RowCnt * N - (long long)(N - RowCnt) * ColCnt);
    }
    puts("");
    return 0;
}
