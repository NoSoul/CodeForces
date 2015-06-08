#include <stdio.h>
#include <string.h>

typedef struct {
    char Name[33];
    int  Score;
} Person_t ;
Person_t P[1000], Input[1000];
char flag[1000];

int main()
{
    int N, i, j, Cnt, Max;
    scanf("%d", &N);
    for(Cnt = i = 0; i < N; ++i) {
        scanf("%s %d", Input[i].Name, &Input[i].Score);
        for(j = 0; j < Cnt; ++j) {
            if(strcmp(P[j].Name, Input[i].Name) == 0) {
                break;
            }
        }
        if(j == Cnt) {
            strcpy(P[j].Name, Input[i].Name);
            ++Cnt;
        }
        P[j].Score += Input[i].Score;
    }
    for(Max = P[0].Score, i = 0; i < Cnt; ++i) {
        if(P[i].Score > Max) {
            Max = P[i].Score;
        }
    }
    for(i = 0; i < Cnt; ++i) {
        if(P[i].Score == Max) {
            flag[i] = 1;
        }
        P[i].Score = 0;
    }
    for(Cnt = i = 0; i < N; ++i) {
        for(j = 0; j < Cnt; ++j) {
            if(strcmp(P[j].Name, Input[i].Name) == 0) {
                break;
            }
        }
        if(j == Cnt) {
            strcpy(P[j].Name, Input[i].Name);
            ++Cnt;
        }
        P[j].Score += Input[i].Score;
        if(P[j].Score >= Max && flag[j]) {
            break;
        }
    }
    printf("%s\n", P[j].Name);
    return 0;
}
