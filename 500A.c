#include <stdio.h>

int A[30001];
char Hash[30001];

int main()
{
    int N, T, i;
    scanf("%d %d", &N, &T);
    Hash[1] = 1;
    for(i = 1; i < N; ++i)
    {
        scanf("%d", &A[i]);
        if(Hash[i])
        {
            Hash[i + A[i]] = 1;
        }
    }
    puts(Hash[T] ? "YES" : "NO");
    return 0;
}
