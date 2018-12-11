#include <stdio.h>

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

int A[100001];

int main()
{
    int n, k, a, len = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &len, a);
    }
    BinaryHeapSort(A, len);
    int pre = 0;
    for(int i = 0, j = 1; i < k; ++i) {
        if(j <= n) {
            printf("%d\n", A[j] - pre);
            pre = A[j];
            while(j + 1 <= n && A[j + 1] == A[j]) {
                ++j;
            }
            ++j;
        } else {
            puts("0");
        }
    }
    return 0;
}
