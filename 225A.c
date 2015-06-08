#include <stdio.h>

int main()
{
    int N, X, A, B, Flag = 1;
    scanf("%d %d", &N, &X);
    while(N--) {
        scanf("%d %d", &A, &B);
        if(Flag && A == X || A == 7 - X || B == X || B == 7 - X) {
            Flag = 0;
        }
    }
    puts(Flag ? "YES" : "NO");
    return 0;
}
