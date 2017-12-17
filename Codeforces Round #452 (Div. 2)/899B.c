#include <stdio.h>

int main()
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                 };
    int a[24];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i <= 60 - n; ++i) {
        char match = 1;
        for(int j = 0; j < n; ++j) {
            if(a[j] != days[i + j]) {
                match = 0;
                break;
            }
        }
        if(match) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
