#include <stdio.h>

int main()
{
    int n;
    int Ans[60000];
    int cnt = 0;
    scanf("%d", &n);
    long long sum = (long long)n * (n + 1) / 2;
    puts(sum & 1 ? "1" : "0");
    sum /= 2;
    while(1) {
        if(sum >= n) {
            Ans[cnt++] = n;
            sum -= n;
        }
        if(sum == 0) {
            break;
        }
        --n;
    }
    printf("%d ", cnt);
    for(int i = 0; i < cnt; ++i) {
        printf("%d ", Ans[i]);
    }
    return 0;
}
