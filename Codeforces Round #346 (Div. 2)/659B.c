#include <stdio.h>
#include <string.h>

typedef struct {
    char name[11];
    int score;
} Node_t;

Node_t Ans[10001][3];

int main()
{
    int n, m, i, j, k;
    scanf("%d %d", &n, &m);
    for(i = 0; i <= m; ++i) {
        Ans[i][0].score = -1;
        Ans[i][1].score = -1;
        Ans[i][2].score = -1;
    }
    char curName[11];
    int region, curScore;
    for(i = 0; i < n; ++i) {
        scanf("%s %d %d", curName, &region, &curScore);
        for(j = 0; j < 3; ++j) {
            if(curScore > Ans[region][j].score) {
                break;
            }
        }
        for(k = 2; k > j; --k) {
            Ans[region][k].score = Ans[region][k - 1].score;
            memset(Ans[region][k].name, 0, sizeof(Ans[region][k].name));
            memcpy(Ans[region][k].name, Ans[region][k - 1].name, strlen(Ans[region][k - 1].name));
        }
        if(j < 3) {
            Ans[region][j].score = curScore;
            memset(Ans[region][j].name, 0, sizeof(Ans[region][j].name));
            memcpy(Ans[region][j].name, curName, strlen(curName));
        }
    }
    for(i = 1; i <= m; ++i) {
        if(Ans[i][2].score == Ans[i][1].score) {
            puts("?");
        } else {
            printf("%s %s\n", Ans[i][0].name, Ans[i][1].name);
        }
    }
    return 0;
}
