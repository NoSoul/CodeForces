#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int n, ansA, ansB = -1;
    scanf("%d", &n);
    for(int i = 1; i < (n + 1) / 2; ++i) {
        int j = n - i;
        if(GCD(i, j) == 1) {
            if(ansB == -1 || ansA * j < ansB * i) {
                ansA = i;
                ansB = j;
            }
        }
    }
    printf("%d %d\n", ansA, ansB);
    return 0;
}
