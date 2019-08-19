#include <stdio.h>
#include <math.h>

void Fun(long long k)
{
    long long ans = 0, bound = 1;
    for(int i = 1; i < 12; ++i) {
        bound *= 10;
        if(k <= ans + i * (bound - bound / 10)) {
            k -= ans;
            --k;
            printf("%d\n", (bound / 10 + k / i) / ((long long)pow(10, i - 1 - k % i)) % 10);
            break;
        }
        ans += i * (bound - bound / 10);
    }
}

int main()
{
    long long k;
    scanf("%I64d", &k);
    Fun(k);
    return 0;
}
