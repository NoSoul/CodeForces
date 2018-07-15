#include <stdio.h>

int Cnt[101];

int main()
{
    int n, a, max = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
        if(max < Cnt[a]) {
            max = Cnt[a];
        }
    }
    printf("%d\n", max);
    return 0;
}
