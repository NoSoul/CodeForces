#include <stdio.h>

int main()
{
    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    if(a < 0)
    {
        a = -a;
    }
    if(b < 0)
    {
        b = -b;
    }
    puts(((s < a + b) || ((s - a - b) % 2 == 1)) ? "No" : "Yes");
    return 0;
}
