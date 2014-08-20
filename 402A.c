#include <stdio.h>

int main()
{
    int k, a, b, v;
    scanf("%d %d %d %d", &k, &a, &b, &v);
    int num = a/v;
    num += (a%v)?1:0;
    int Ans = 0;
    while(1)
    {
        if(b >= k-1)
        {
            b -= k-1;
            a -= k*v;
            ++Ans;
        }
        else if(b>0)
        {
            a -= (b+1)*v;
            b = 0;
            ++Ans;
        }
        else
        {
            a -= v;
            ++Ans;
        }
        if(a<=0)
        {
            break;
        }
    }
    printf("%d\n",Ans);
    return 0;
}
