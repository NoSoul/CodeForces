#include <stdio.h>

int f[5001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
    }
    for(int i = 1; i <= n; ++i) {
        if(f[f[f[i]]] == i) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
