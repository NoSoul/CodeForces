#include <stdio.h>

int Status[101];

int main()
{
    int N, M, num, i;
    scanf("%d %d", &N, &M);
    while(M--)
    {
        scanf("%d", &num);
        for(i=num; i<=N; ++i)
        {
            if(Status[i] != 0)
            {
                break;
            }
            Status[i] = num;
        }
    }
    for(i=1; i<=N; ++i)
    {
        printf("%d ", Status[i]);
    }
    return 0;
}
