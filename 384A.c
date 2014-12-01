#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    printf("%d\n", (n + 1) / 2 * ((n + 1) / 2) + n / 2 * (n / 2));
    for(i = 0; i < n; ++i)
    {
        if(i & 1)
        {
            for(j = 0; j < n; ++j)
            {
                putchar((j & 1) ? 'C' : '.');
            }
        }
        else
        {
            for(j = 0; j < n; ++j)
            {
                putchar((j & 1) ? '.' : 'C');
            }
        }
        printf("\n");
    }
    return 0;
}
