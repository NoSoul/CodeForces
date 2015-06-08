#include <stdio.h>

int Hash[6001];

int main()
{
    int N, i, j, Num, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        ++Hash[Num];
    }
    for(i = 0; i < 6001; ++i) {
        while(Hash[i] > 1) {
            for(j = i + 1; j < 6001; ++j) {
                if(Hash[j] == 0) {
                    Hash[j] = 1;
                    --Hash[i];
                    Ans += j - i;
                    break;
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
