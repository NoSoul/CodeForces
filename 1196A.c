#include <stdio.h>

int main()
{
    int q;
    long long a[3];
    scanf("%d", &q);
    while(q--) {
        for(int i = 0; i < 3; ++i) {
            scanf("%I64d", &a[i]);
        }
        for(int i = 0; i < 3; ++i) {
            for(int j = i + 1; j < 3; ++j) {
                if(a[j] > a[i]) {
                    long long temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        long long delta = a[1] - a[0];
        if(a[2] < delta) {
            printf("%I64d\n", a[0] + a[2]);
        } else {
            printf("%I64d\n", a[1] + (a[2] - delta) / 2);
        }
    }
    return 0;
}
