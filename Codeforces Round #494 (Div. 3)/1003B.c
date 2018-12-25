#include <stdio.h>

int main()
{
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    if(x & 1) {
        int remainA = a - (x + 1) / 2;
        int remainB = b - (x + 1) / 2;
        for(int i = 0; i < remainB; ++i) {
            putchar('1');
        }
        for(int i = 0; i < (x + 1) / 2; ++i) {
            putchar('1');
            putchar('0');
        }
        for(int i = 0; i < remainA; ++i) {
            putchar('0');
        }
    } else {
        if(b > a) {
            int remainA = a - x / 2;
            int remainB = b - x / 2 - 1;
            for(int i = 0; i < remainB; ++i) {
                putchar('1');
            }
            for(int i = 0; i < x / 2; ++i) {
                putchar('1');
                putchar('0');
            }
            for(int i = 0; i < remainA; ++i) {
                putchar('0');
            }
            putchar('1');
        } else {
            int remainA = a - x / 2 - 1;
            int remainB = b - x / 2;
            for(int i = 0; i < remainA; ++i) {
                putchar('0');
            }
            for(int i = 0; i < x / 2; ++i) {
                putchar('0');
                putchar('1');
            }
            for(int i = 0; i < remainB; ++i) {
                putchar('1');
            }
            putchar('0');
        }
    }
    return 0;
}
