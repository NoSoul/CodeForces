#include <stdio.h>

int Ruler[100000];

int Binary_Search(const int *Array, const int len, const int key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = len-1;
    while(Left <= Right)
    {
        Mid = (Left+Right)>>1;
        if(Array[Mid] == key)
        {
            return Mid;
        }
        else if(Array[Mid] > key)
        {
            Right = Mid-1;
        }
        else
        {
            Left = Mid+1;
        }
    }
    return -1;
}

int main()
{
    int N, L, X, Y, i;
    char XOK, YOK;
    scanf("%d %d %d %d", &N, &L, &X, &Y);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &Ruler[i]);
    }
    XOK = 0;
    for(i=0; i<N-1; ++i)
    {
        if(Ruler[i]+X > L)
        {
            break;
        }
        if(~Binary_Search(Ruler, N, Ruler[i]+X))
        {
            XOK = 1;
            break;
        }
    }
    YOK = 0;
    for(i=0; i<N-1; ++i)
    {
        if(Ruler[i]+Y > L)
        {
            break;
        }
        if(~Binary_Search(Ruler, N, Ruler[i]+Y))
        {
            YOK = 1;
            break;
        }
    }
    if(XOK && YOK)
    {
        puts("0");
    }
    else if(XOK && !YOK)
    {
        printf("1\n%d\n", Y);
    }
    else if(!XOK && YOK)
    {
        printf("1\n%d\n", X);
    }
    else
    {
        char One = 0;
        int newpos;
        for(i=0; i<N; ++i)
        {
            newpos = Ruler[i] + X;
            if(newpos <= L)
            {
                if(newpos-Y >= 0)
                {
                    if(~Binary_Search(Ruler, N, newpos-Y))
                    {
                        One = 1;
                        break;
                    }
                }
                if(newpos+Y <= L)
                {
                    if(~Binary_Search(Ruler, N, newpos+Y))
                    {
                        One = 1;
                        break;
                    }
                }
            }
            newpos = Ruler[i] - X;
            if(newpos >= 0)
            {
                if(newpos-Y >= 0)
                {
                    if(~Binary_Search(Ruler, N, newpos-Y))
                    {
                        One = 1;
                        break;
                    }
                }
                if(newpos+Y <= L)
                {
                    if(~Binary_Search(Ruler, N, newpos+Y))
                    {
                        One = 1;
                        break;
                    }
                }
            }
        }
        if(One)
        {
            printf("1\n%d\n", newpos);
        }
        else
        {
            printf("2\n%d %d\n", X, Y);
        }
    }
    return 0;
}
