#include <stdio.h>

int main()
{
    int Cnt = 0, a, b, n, m;
    scanf("%d %d", &n, &m);
    for(a = 0; a <= m; ++a)
    {
        for(b = 0; b <= m; ++b)
        {
            if(a * a + b == n && a + b * b == m)
            {
                ++Cnt;
            }
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
