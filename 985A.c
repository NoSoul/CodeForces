#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int P[50];
int Queue[50];
char Flag[101];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, cur, len, ans = 0x7f7f7f7f;
    scanf("%d", &n);
    for(int i = 0; i < n / 2; ++i) {
        scanf("%d", &P[i]);
    }
    qsort(P, n / 2, sizeof(int), cmp);
    memset(Flag, 0, sizeof(Flag));
    cur = len = 0;
    for(int i = 0; i < n / 2; ++i) {
        if(P[i] & 1) {
            Flag[P[i]] = 1;
        } else {
            Queue[len++] = P[i];
        }
    }
    for(int i = n - 1; i >= 1; i -= 2) {
        if(!Flag[i]) {
            cur += abs(i - Queue[len - 1]);
            --len;
        }
    }
    if(ans > cur) {
        ans = cur;
    }
    memset(Flag, 0, sizeof(Flag));
    cur = len = 0;
    for(int i = 0; i < n / 2; ++i) {
        if(!(P[i] & 1)) {
            Flag[P[i]] = 1;
        } else {
            Queue[len++] = P[i];
        }
    }
    for(int i = n; i > 1; i -= 2) {
        if(!Flag[i]) {
            cur += abs(i - Queue[len - 1]);
            --len;
        }
    }
    if(ans > cur) {
        ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
