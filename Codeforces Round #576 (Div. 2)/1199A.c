#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, x, y;
    int a[100001];
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        bool check = true;
        for(int j = i - 1; j >= i - x && j >= 0; --j) {
            check &= a[j] > a[i];
        }
        for(int j = i + 1; j <= i + y && j < n; ++j) {
            check &= a[j] > a[i];
        }
        if(check) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
