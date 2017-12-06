#include <stdio.h>

int main()
{
    int n, m;
    char str[101];
    scanf("%d %d %s", &n, &m, str);
    while(m--) {
        int l, r;
        char c1, c2;
        scanf("%d %d %c %c", &l, &r, &c1, &c2);
        --l;
        --r;
        for(int i = l; i <= r; ++i) {
            if(str[i] == c1) {
                str[i] = c2;
            }
        }
    }
    puts(str);
    return 0;
}
