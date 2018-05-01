#include <stdio.h>

int main()
{
    long long n, minRemain, choiceA, a, k, choiceIdx;
    scanf("%I64d %I64d", &n, &k);
    minRemain = n;
    if(n == 0) {
        printf("1 0\n");
        return 0;
    }
    for(long long i = 0; i < k; ++i) {
        scanf("%I64d", &a);
        if(minRemain > n % a) {
            minRemain = n % a;
            choiceA = a;
            choiceIdx = i + 1;
        }
    }
    if(minRemain == n) {
        printf("1 0\n");
    } else {
        printf("%I64d %I64d\n", choiceIdx, (n - minRemain) / choiceA);
    }
    return 0;
}
