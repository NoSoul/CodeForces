#include <stdio.h>

int main()
{
    int N, i;
    char Str[101];
    scanf("%d", &N);
    scanf("%s", Str);
    for(i=0; i<N; ++i)
    {
        if(Str[i] == '0')
        {
            break;
        }
    }
    if(i < N)
    {
        ++i;
    }
    printf("%d\n", i);
    return 0;
}
