#include <stdio.h>
#include <stdlib.h>

typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val > array[now >> 1]) {
        array[now] = array[now >> 1];
        now >>= 1;
    }
    array[now] = val;
}

DataType_t BinaryHeapPop(DataType_t *array, int *len)
{
    DataType_t ret = array[1];
    int now = 1, temp;
    while((now << 1) <= *len) {
        temp = now << 1;
        if((temp + 1) <= *len && array[temp + 1] > array[temp]) {
            ++temp;
        }
        if(array[temp] > array[*len]) {
            array[now] = array[temp];
        } else {
            break;
        }
        now = temp;
    }
    array[now] = array[*len];
    --(*len);
    return ret;
}

void BinaryHeapSort(DataType_t *array, int len)
{
    while(len) {
        int curIdx = len;
        array[curIdx] = BinaryHeapPop(array, &len);
    }
}

int X[300001];

int main()
{
    int n, ans, num, len = 0;
    long long distA, distB, min;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(X, &len, num);
    }
    BinaryHeapSort(X, n);
    distA = distB = 0;
    for(int i = 2; i <= n; ++i) {
        distB += X[i] - X[1];
    }
    min = distB;
    ans = X[1];
    for(int i = 2; i <= n; ++i) {
        distA += ((long long)(i - 1)) * (X[i] - X[i - 1]);
        distB -= ((long long)(n - i + 1)) * (X[i] - X[i - 1]);
        if(min > distA + distB) {
            min = distA + distB;
            ans = X[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
