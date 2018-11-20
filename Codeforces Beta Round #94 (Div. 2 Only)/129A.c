#include <stdio.h>

char Hash[101];

int main()
{
    int N, i, sum, cnt;
    sum = cnt = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &i);
        ++Hash[i];
        sum += i;
    }
    for(i = 1; i < 101; ++i) {
        if(Hash[i]) {
            if(!((sum - i) & 1)) {
                cnt += Hash[i];
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
