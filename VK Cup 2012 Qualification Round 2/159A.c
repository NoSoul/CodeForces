#include <stdio.h>
#include <string.h>

typedef struct {
    char m_stra[21];
    char m_strb[21];
    int  m_t;
} Node_t ;
Node_t Data[1010];

char Str[2010][21];
int Size, Cnt;
char Map[1010][1010];
int Res[1010][2];

int GetId(char *str)
{
    int i;
    for(i = 0; i < Size; ++i) {
        if(strcmp(Str[i], str) == 0) {
            return i;
        }
    }
    strcpy(Str[i], str);
    return Size++;
}

int main()
{
    int N, d, i, j, x, y;
    scanf("%d %d", &N, &d);
    for(i = 0; i < N; ++i) {
        scanf("%s %s %d", Data[i].m_stra, Data[i].m_strb, &Data[i].m_t);
    }
    for(i = 0; i < N - 1; ++i) {
        for(j = i + 1; j < N; ++j) {
            if(Data[i].m_t == Data[j].m_t || (Data[i].m_t + d < Data[j].m_t) || strcmp(Data[i].m_stra, Data[j].m_strb) != 0 || strcmp(Data[i].m_strb, Data[j].m_stra) != 0) {
                continue;
            }
            x = GetId(Data[i].m_stra);
            y = GetId(Data[i].m_strb);
            if(Map[x][y] == 0) {
                Map[x][y] = Map[y][x] = 1;
                Res[Cnt][0] = x;
                Res[Cnt][1] = y;
                ++Cnt;
            }
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i) {
        printf("%s %s\n", Str[Res[i][0]], Str[Res[i][1]]);
    }
    return 0;
}
