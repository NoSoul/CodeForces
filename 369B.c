#include <stdio.h>

void Show(int sum, int n, int l, int r)
{
    if(n == 0)
    {
        return;
    }
    int i, j, mod = sum % n;
    for(i = 0; i < n; ++i)
    {
        j = sum / n;
        if(mod > 0)
        {
            --mod;
            ++j;
        }
        printf("%d ", j);
    }
}

int main()
{
    int N, K, L, R, SAll, SK;
    scanf("%d %d %d %d %d %d", &N, &K, &L, &R, &SAll, &SK);
    Show(SK, K, L, R);
    Show(SAll - SK, N - K, L, R);
    return 0;
}
