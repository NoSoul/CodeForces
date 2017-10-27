#include <stdio.h>
#include <string.h>

typedef struct {
    char FL[11];
    char SL[11];
    int id;
} Node_t;
Node_t Data[3000];

int main()
{
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; ++i) {
        scanf("%s %s", Data[i].FL, Data[i].SL);
        Data[i].id = 0;
        if(strlen(Data[i].SL) < strlen(Data[i].FL)) {
            Data[i].id = 1;
        }
    }
    char Str[11];
    for(i = 0; i < N; ++i) {
        scanf("%s", Str);
        for(j = 0; j < M; ++j) {
            if(strcmp(Data[j].FL, Str) == 0) {
                printf("%s ", Data[j].id == 0 ? Data[j].FL : Data[j].SL);
                break;
            }
        }
    }
    puts("");
    return 0;
}
