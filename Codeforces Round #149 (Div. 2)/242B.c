#include <stdio.h>

int Ans[100001][2];

int main()
{
    int N, i, Min, Max;
    scanf("%d", &N);
    scanf("%d %d", &Ans[0][0], &Ans[0][1]);
    Min = Ans[0][0];
    Max = Ans[0][1];
    for(i = 1; i < N; ++i) {
        scanf("%d %d", &Ans[i][0], &Ans[i][1]);
        if(Ans[i][0] < Min) {
            Min = Ans[i][0];
        }
        if(Ans[i][1] > Max) {
            Max = Ans[i][1];
        }
    }
    for(i = 0; i < N; ++i) {
        if(Min == Ans[i][0] && Ans[i][1] == Max) {
            break;
        }
    }
    if(i == N) {
        printf("-1\n");
    } else {
        printf("%d\n", i + 1);
    }
    return 0;
}
