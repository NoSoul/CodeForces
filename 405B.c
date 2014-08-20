#include <stdio.h>

int main()
{
    int N, i, j, k, l, Ans;
    char Str[3001];
    scanf("%d", &N);
    scanf("%s", Str);
    for(i=0; Str[i]!='\0'; ++i)
    {
        if(Str[i] == 'L')
        {
            for(j=i-1; j>=0; --j)
            {
                Str[j] = 'L';
            }
        }
        else if(Str[i] == 'R')
        {
            for(j=i+1; Str[j]!='\0'&&Str[j]!='L'; ++j);
            if(Str[j]=='\0')
            {
                for(j=i+1; Str[j]!='\0'; ++j)
                {
                    Str[j] = 'R';
                }
            }
            else
            {
                int num = (j-i-1)/2;
                for(l=i+1,k=0; k<num; ++l,++k)
                {
                    Str[l] = 'R';
                }
                for(l=j-1,k=0; k<num; --l,++k)
                {
                    Str[l] = 'L';
                }
            }
            i = j;
        }
    }
    Ans = 0;
    for(i=0; i<N; ++i)
    {
        Ans += Str[i]=='.';
    }
    printf("%d\n", Ans);
    return 0;
}
