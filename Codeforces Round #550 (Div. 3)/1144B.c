#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int n, a, sum = 0;
    int Data[2][2000];
    int cnt[2] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        Data[a & 1][cnt[a & 1]++] = a;
        sum += a;
    }
    qsort(Data[0], cnt[0], sizeof(int), cmp);
    qsort(Data[1], cnt[1], sizeof(int), cmp);
    if(abs(cnt[0] - cnt[1]) > 1) {
        if(cnt[0] > cnt[1]) {
            for(int i = 0; i < cnt[1]; ++i) {
                sum -= Data[0][i];
                sum -= Data[1][i];
            }
            sum -= Data[0][cnt[1]];
        } else {
            for(int i = 0; i < cnt[0]; ++i) {
                sum -= Data[0][i];
                sum -= Data[1][i];
            }
            sum -= Data[1][cnt[0]];
        }
        printf("%d\n", sum);
    } else {
        puts("0");
    }
    return 0;
}
