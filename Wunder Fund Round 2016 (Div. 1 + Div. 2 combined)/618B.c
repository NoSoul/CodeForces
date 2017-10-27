#include <stdio.h>
#include <string.h>

#define MAXN    51

char Flag[MAXN];

int main()
{
    int N, i, j, num;
    int Cnt[MAXN];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        memset(Cnt, 0, sizeof(Cnt));
        for(j = 0; j < N; ++j) {
            scanf("%d", &num);
            ++Cnt[num];
        }
        int maxCnt = 1;
        int maxVal = -1;
        for(j = 1; j <= N; ++j) {
            if(Cnt[j] > maxCnt) {
                maxCnt = Cnt[j];
                maxVal = j;
            }
        }
        if(maxVal == -1) {
            for(j = N; j >= 0; --j) {
                if(!Flag[j]) {
                    Flag[j] = 1;
                    printf("%d ", j);
                    break;
                }
            }
        } else {
            Flag[maxVal] = 1;
            printf("%d ", maxVal);
        }
    }
    puts("");
    return 0;
}
