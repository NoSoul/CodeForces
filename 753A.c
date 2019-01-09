#include <stdio.h>

int main()
{
    int n;
    int ans[1000];
    int size = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        if(n >= i) {
            ans[size++] = i;
            n -= i;
        }
    }
    ans[size - 1] += n;
    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
