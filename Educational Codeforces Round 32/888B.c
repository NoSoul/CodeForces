#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, max;
    char str[101];
    int U, D, L, R;
    max = U = D = L = R = 0;
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        if(str[i] == 'U') {
            ++U;
        } else if(str[i] == 'D') {
            ++D;
        } else if(str[i] == 'L') {
            ++L;
        } else {
            ++R;
        }
    }
    printf("%d\n", min(U, D) * 2 + min(L, R) * 2);
    return 0;
}
