#include <stdio.h>
#include <stdbool.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        int p[200];
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            --p[i];
        }
        bool clockwise = true;
        for(int i = 1; i < n; ++i) {
            clockwise &= (p[i] == (p[i - 1] + 1) % n);
        }
        bool counterclockwise = true;
        for(int i = 1; i < n; ++i) {
            counterclockwise &= (p[i] == (p[i - 1] - 1 + n) % n);
        }
        puts(clockwise || counterclockwise ? "YES" : "NO");
    }
    return 0;
}
