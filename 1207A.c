#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int b, p, f, h, c;
        scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
        if(h >= c) {
            int a = Min(b / 2, p);
            printf("%d\n", a * h + c * Min((b - 2 * a) / 2, f));
        } else {
            int a = Min(b / 2, f);
            printf("%d\n", a * c + h * Min((b - 2 * a) / 2, p));
        }
    }
    return 0;
}
