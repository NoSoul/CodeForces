#include <stdio.h>

int main()
{
    int b, k, a;
    scanf("%d %d", &b, &k);
    int cnt = 0;
    for(int i = 0; i < k; ++i) {
        scanf("%d", &a);
        if(i != k - 1) {
            cnt += (a & 1) && (b & 1);
        } else {
            cnt += a & 1;
        }
    }
    puts(cnt & 1 ? "odd" : "even");
    return 0;
}
