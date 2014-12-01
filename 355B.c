#include <stdio.h>

int main()
{
    int c1, c2, c3, c4, n, m, num, i, sumn = 0, summ = 0;
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        if(num * c1 < c2)
        {
            sumn += num * c1;
        }
        else
        {
            sumn += c2;
        }
    }
    if(sumn > c3)
    {
        sumn = c3;
    }
    for(i = 0; i < m; ++i)
    {
        scanf("%d", &num);
        if(num * c1 < c2)
        {
            summ += num * c1;
        }
        else
        {
            summ += c2;
        }
    }
    if(summ > c3)
    {
        summ = c3;
    }
    sumn += summ;
    if(sumn > c4)
    {
        sumn = c4;
    }
    printf("%d\n", sumn);
    return 0;
}
