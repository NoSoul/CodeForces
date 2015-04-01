#include <stdio.h>

char Str[200001];
int A[26];

int main()
{
    int i, Ans = 0;
    scanf("%*d %s", Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] >= 'a' && Str[i] <= 'z')
        {
            ++A[Str[i] - 'a'];
        }
        else
        {
            if(A[Str[i] - 'A'])
            {
                --A[Str[i] - 'A'];
            }
            else
            {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
