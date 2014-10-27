#include <stdio.h>

int main()
{
    long long l, r;
    scanf("%I64d %I64d", &l, &r);
    if((l&1) == 0)
    {
        if(r-l < 2)
        {
            puts("-1");
            return 0;
        }
        printf("%I64d %I64d %I64d\n", l, l+1, l+2);
    }
    else
    {
        if(r-l < 3)
        {
            puts("-1");
            return 0;
        }
        ++l;
        printf("%I64d %I64d %I64d\n", l, l+1, l+2);
    }
    return 0;
}
