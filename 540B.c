#include <stdio.h>

int main()
{
    int n, k, p, x, y, i, Sum = 0, SetNum = 0;
    int A[999];
    scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
    for(i = 0; i < k; ++i) {
        scanf("%d", &A[i]);
        Sum += A[i];
        if(A[i] >= y) {
            ++SetNum;
        }
    }
    int KindA, KindB;
    KindB = (n + 1) / 2 - SetNum;
    if(KindB > n - k) {
        puts("-1");
        return 0;
    }
    if(KindB < 0) {
        KindB = 0;
    }
    KindA = n - k - KindB;
    for(i = KindA + y * KindB; i <= (n - k)*p; ++i) {
        if(Sum + i <= x) {
            int r = i - (KindA + y * KindB);
            for(i = 0; i < KindB; ++i) {
                if(r) {
                    if(y + r < p) {
                        printf("%d ", y + r);
                        r = 0;
                    } else {
                        printf("%d ", p);
                        r -= p - y;
                    }
                } else {
                    printf("%d ", y);
                }
            }
            for(i = 0; i < KindA; ++i) {
                if(r) {
                    if(1 + r < p) {
                        printf("%d ", 1 + r);
                        r = 0;
                    } else {
                        printf("%d ", p);
                        r -= p - 1;
                    }
                } else {
                    printf("1 ");
                }
            }
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}
