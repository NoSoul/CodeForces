#include <stdio.h>

char Flag[1001];

int main()
{
    int N, i, num;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &num);
        ++Flag[num];
    }
    for(i = 1; i < 1001; ++i)
    {
        if(Flag[i] > ((N >> 1) + (N & 1)))
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
