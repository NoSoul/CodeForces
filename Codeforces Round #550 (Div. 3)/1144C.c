#include <stdio.h>

char Flag[200001];

int main()
{
    int n, a;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Flag[a];
        if(Flag[a] == 2) {
            ++cnt;
        } else if(Flag[a] == 3) {
            puts("NO");
            return 0;
        }
    }
    printf("YES\n%d\n", cnt);
    for(int i = 0; i < 200001; ++i) {
        if(Flag[i] == 2) {
            printf("%d ", i);
        }
    }
    printf("\n%d\n", n - cnt);
    for(int i = 200001; i >= 0; --i) {
        if(Flag[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
