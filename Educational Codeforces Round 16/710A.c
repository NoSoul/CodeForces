#include <stdio.h>

int Fun(int x, int y)
{
    int ret = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            int xPrime = x - 1 + i;
            int yPrime = y - 1 + j;
            if(xPrime >= 0 && xPrime < 8 && yPrime >= 0 && yPrime < 8) {
                ++ret;
            }
        }
    }
    return ret - 1;
}

int main()
{
    int x, y;
    char str[3];
    scanf("%s", str);
    x = str[0] - 'a';
    y = 8 - (str[1] - '0');
    printf("%d\n", Fun(x, y));
    return 0;
}
