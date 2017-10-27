#include <stdio.h>

int main()
{
    int N, before, after;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%*s %d %d", &before, &after);
        if(before >= 2400 && after > before) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
