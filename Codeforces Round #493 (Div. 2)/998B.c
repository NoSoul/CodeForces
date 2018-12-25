#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, B;
    int a[100];
    int c[100];
    scanf("%d %d", &n, &B);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int even = 0, odd = 0, ans = 0, cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] & 1) {
            ++odd;
        } else {
            ++even;
        }
        if(even == odd && i + 1 < n && abs(a[i] - a[i + 1]) <= B) {
            c[cnt++] = abs(a[i] - a[i + 1]);
        }
    }
    for(int i = 0; i < cnt; ++i) {
        int k = i;
        for(int j = i + 1; j < cnt; ++j) {
            if(c[k] > c[j]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = c[i];
            c[i] = c[k];
            c[k] = temp;
        }
    }
    for(int i = 0; i < cnt; ++i) {
        if(B >= c[i]) {
            B -= c[i];
            ++ans;
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
