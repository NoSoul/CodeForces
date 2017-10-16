#include <stdio.h>

char Flag[300001];

int main()
{
    int n, num, bound, Cnt = 0;
    scanf("%d", &n);
    printf("%d ", 1);
    bound = n;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ++Cnt;
        Flag[num] = 1;
        while(Flag[bound]) {
            --bound;
            --Cnt;
        }
        printf("%d ", Cnt + 1);
    }
    puts("");
    return 0;
}
