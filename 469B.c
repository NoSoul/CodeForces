#include <stdio.h>

typedef struct
{
    int s, e;
} Node_t;

int Judge(int x1, int y1, int x2, int y2)
{
    if(x2>=x1 && x2<=y1)
    {
        return 1;
    }
    if(y2>=x1 && y2<=y1)
    {
        return 1;
    }
    if(x2<=x1 && y2>=y1)
    {
        return 1;
    }
    if(x2>=x1 && y2<=y1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int p, q, l, r, Ans;
    int i, j, k;
    Node_t X[50], Z[50];
    Ans = 0;
    scanf("%d %d %d %d", &p, &q, &l, &r);
    for(i=0; i<p; ++i)
    {
        scanf("%d %d", &Z[i].s, &Z[i].e);
    }
    for(i=0; i<q; ++i)
    {
        scanf("%d %d", &X[i].s, &X[i].e);
    }
    for(k=l; k<=r; ++k)
    {
        char flag = 0;
        for(i=0; i<p&&!flag; ++i)
        {
            for(j=0; j<q&&!flag; ++j)
            {
                if(Judge(Z[i].s, Z[i].e, X[j].s+k, X[j].e+k))
                {
                    flag = 1;
                }
            }
        }
        Ans += flag;
    }
    printf("%d\n", Ans);
    return 0;
}
