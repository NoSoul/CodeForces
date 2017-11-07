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

int A[200001];

int main()
{
    int n, num, len = 0, min, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(A, &len, num);
    }
    BinaryHeapSort(A, n);
    min = A[2] - A[1];
    for(int i = 3; i <= n; ++i) {
        if(min > A[i] - A[i - 1]) {
            min = A[i] - A[i - 1];
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(min == A[i] - A[i - 1]) {
            ++cnt;
        }
    }
    printf("%d %d\n", min, cnt);
    return 0;
}
