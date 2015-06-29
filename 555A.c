#include <stdio.h>

int main()
{
    int N, K, M, i, j, Num, Pre, Ans = 0;
    scanf("%d %d", &N, &K);
    for(i = 0; i < K; ++i) {
        scanf("%d", &M);
        int idx = -1;
        char flag = 0;
        for(j = 0; j < M; ++j) {
            scanf("%d", &Num);
            if(Num == 1) {
                flag = 1;
            }
            if(j != 0 && flag && idx == -1) {
                if(Num != Pre + 1) {
                    idx = j;
                }
            }
            Pre = Num;
        }
        if(idx == -1) {
            idx = M;
        }
        if(!flag) {
            Ans += M - 1 + M;
        } else {
            Ans += (M - idx) + (M - idx + 1);
        }
    }
    --Ans;
    printf("%d\n", Ans);
    return 0;
}
