#include <stdio.h>

int Hash[1001];

int main()
{
    int N, i, t;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &t);
        Hash[t] = 1;
    }
    for(i = 2; i < 1000; ++i) {
        if(Hash[i] && Hash[i - 1] && Hash[i + 1]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
