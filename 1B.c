#include <stdio.h>
#include <string.h>

int C2N(char *s)
{
    int i,r;
    for(r=i=0; s[i]!='\0'; ++i)
    {
        r*=26;
        r+=s[i]-'A'+1;
    }
    return r;
}

char* N2C(int N)
{
    int i=0,j;
    char r[20];
    while(N)
    {
        j=N%26;
        if(j==0)
        {
            j=26;
        }
        r[i++]=j-1+'A';
        N/=26;
        if(j==26)
        {
            --N;
        }
    }
    r[i]='\0';
    strrev(r);
    return r;
}

int Judge(char *s)
{
    int i,l;
    l=strlen(s);
    for(i=0; s[i]!='\0'; ++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            break;
        }
    }
    for(; s[i]!='\0'; ++i)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            break;
        }
    }
    if(i<l)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int T,R,C,i,j;
    char Str[20],Ans[20];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",Str);
        if(Judge(Str))
        {
            for(i=j=0; Str[i]!='\0'; ++i)
            {
                if(Str[i]>='0'&&Str[i]<='9')
                {
                    break;
                }
                else
                {
                    Ans[j++]=Str[i];
                }
            }
            Ans[j]='\0';
            for(R=0; Str[i]!='\0'; ++i)
            {
                R*=10;
                R+=Str[i]-'0';
            }
            C=C2N(Ans);
            printf("R%dC%d\n",R,C);
        }
        else
        {
            for(R=0,i=1; Str[i]!='\0'; ++i)
            {
                if(Str[i]=='C')
                {
                    break;
                }
                else
                {
                    R*=10;
                    R+=Str[i]-'0';
                }
            }
            for(C=0,++i; Str[i]!='\0'; ++i)
            {
                C*=10;
                C+=Str[i]-'0';
            }
            strcpy(Ans,N2C(C));
            printf("%s%d\n",Ans,R);
        }
    }
    return 0;
}
