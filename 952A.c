#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    puts(a & 1 ? "1" : "0");
    return 0;
}
