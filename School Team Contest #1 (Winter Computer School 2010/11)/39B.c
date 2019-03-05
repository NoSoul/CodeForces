#include <stdio.h>

int main()
{
    int n, a, size = 0, expect = 1;
    int ans[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a == expect) {
            ++expect;
            ans[size++] = 2001 + i;
        }
    }
    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
