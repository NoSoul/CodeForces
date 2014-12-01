#include <stdio.h>

char Data[200];
int Hash[100];
char Pre[100];

int main()
{
    int N, i, A, B, C, Last, extra;
    scanf("%d", &N);
    Last = 0;
    for(i = 0; i < N + N; ++i)
    {
        scanf("%d", &Data[i]);
        ++Hash[Data[i]];
    }
    for(A = B = C = 0, i = 10; i < 100; ++i)
    {
        if(Hash[i] > 1)
        {
            ++A;
            ++B;
        }
        else if(Hash[i] == 1)
        {
            ++C;
        }
    }
    A += C / 2;
    B += C / 2;
    if(C & 1)
    {
        ++B;
    }
    printf("%d\n", A * B);
    extra = (C & 1) ? 1 : 0;
    for(i = 0; i < N + N; ++i)
    {
        if(Hash[Data[i]] == 1)
        {
            putchar(Last ? '2' : '1');
            Last ^= 1;
            putchar(' ');
        }
        else if(Hash[Data[i]] == 2)
        {
            putchar(Pre[Data[i]] ? '2' : '1');
            Pre[Data[i]] ^= 1;
            putchar(' ');
        }
        else
        {
            putchar(extra ? '2' : '1');
            extra ^= 1;
            putchar(' ');
            --Hash[Data[i]];
        }
    }
    return 0;
}
