#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        printf("%s ", i & 1 ? "I love that" : "I hate that");
    }
    printf("%s\n", n & 1 ? "I hate it" : "I love it");
    return 0;
}
