#include <stdio.h>

int main()
{
    int m, i, cnt = 0;
    scanf("%d", &m);
    for(i = 1; cnt < m; ++i) {
        int j = i;
        while(j && j % 5 == 0) {
            ++cnt;
            j /= 5;
        }
    }
    if(cnt != m) {
        puts("0");
    } else {
        printf("5\n");
        printf("%d %d %d %d %d\n", i - 1, i, i + 1, i + 2, i + 3);
    }
    return 0;
}
