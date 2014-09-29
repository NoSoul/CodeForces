#include <stdio.h>
#include <string.h>

typedef struct
{
    char f[51];
    char s[51];
} Name_t;
Name_t P[100000];

int main()
{
    int N, i, Num;
    char Base[51];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%s %s", &P[i].f, &P[i].s);
    }
    if(N == 1)
    {
        puts("YES");
        return 0;
    }
    int Len;
    for(i=0; i<N; ++i)
    {
        scanf("%d", &Num);
        --Num;
        if(i==0)
        {
            Len = strlen(P[Num].f);
            strncpy(Base, P[Num].f, Len);
            Base[Len] = '\0';
            if(strcmp(Base, P[Num].s)>0)
            {
                Len = strlen(P[Num].s);
                strncpy(Base, P[Num].s, Len);
                Base[Len] = '\0';
            }
        }
        else
        {
            if(strcmp(P[Num].f, Base)>0 && strcmp(P[Num].s, Base)>0)
            {
                if(strcmp(P[Num].f, P[Num].s)<0)
                {
                    Len = strlen(P[Num].f);
                    strncpy(Base, P[Num].f, Len);
                    Base[Len] = '\0';
                }
                else
                {
                    Len = strlen(P[Num].s);
                    strncpy(Base, P[Num].s, Len);
                    Base[Len] = '\0';
                }
            }
            else if(strcmp(P[Num].f, Base)>0)
            {
                Len = strlen(P[Num].f);
                strncpy(Base, P[Num].f, Len);
                Base[Len] = '\0';
            }
            else if(strcmp(P[Num].s, Base)>0)
            {
                Len = strlen(P[Num].s);
                strncpy(Base, P[Num].s, Len);
                Base[Len] = '\0';
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
