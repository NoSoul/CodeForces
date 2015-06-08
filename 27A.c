#include <stdio.h>

char Hash[3001];

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &j);
        Hash[j] = 1;
    }
    for(i = 1; i < 3001; ++i) {
        if(!Hash[i]) {
            break;
        }
    }
    printf("%d\n", i);
    return 0;
}
