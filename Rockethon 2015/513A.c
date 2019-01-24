#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d %*d %*d", &A, &B);
    puts(A > B ? "First" : "Second");
    return 0;
}
