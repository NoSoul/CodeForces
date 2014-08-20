#include <stdio.h>

char T[8]= {"><+-.,[]"};
int Base[8]= {8,9,10,11,12,13,14,15};

int main()
{
    int i,j,Ans;
    char Str[101];
    scanf("%s",&Str);
    for(Ans=i=0; Str[i]!='\0'; ++i)
    {
        for(j=0; j<8; ++j)
        {
            if(Str[i]==T[j])
            {
                break;
            }
        }
        Ans=(Ans*16+Base[j])%1000003;
    }
    printf("%d\n",Ans);
    return 0;
}
