#include <stdio.h>

typedef struct
{
    char ch;
    int r, c;
} Node_t;
Node_t Cur;
Node_t Stack[60*60];
int Size;

int main()
{
    int N, i, j, k;
    char Str[53];
    scanf("%d\n", &N);
    for(i=0; i<N; ++i)
    {
        fgets(Str, 52, stdin);
        for(j=0; Str[j] !='\0'; ++j)
        {
            Cur.r = i+1;
            Cur.c = j+1;
            Cur.ch = Str[j];
            if(Str[j]>='a' && Str[j]<='z')
            {
                for(k=Size-1; k>=0; --k)
                {
                    if(Cur.ch == Stack[k].ch)
                    {
                        printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", Cur.r, Cur.c, Cur.ch, Stack[k].r, Stack[k].c);
                        break;
                    }
                }
                Stack[Size++] = Cur;
            }
            else if(Str[j] == '{')
            {
                Stack[Size++] = Cur;
            }
            else if(Str[j] == '}')
            {
                while(Stack[Size-1].ch != '{')
                {
                    --Size;
                }
                --Size;
            }
        }
    }
    return 0;
}
