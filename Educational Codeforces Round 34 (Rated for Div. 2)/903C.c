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

int main()
{
    int n, len = 0, ans = 1;
    int A[5001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        BinaryHeapPush(A, &len, a);
    }
    BinaryHeapSort(A, len);
    int cur = 1;
    for(int i = 2; i <= len; ++i) {
        if(A[i] == A[i - 1]) {
            ++cur;
        } else {
            if(ans < cur) {
                ans = cur;
            }
            cur = 1;
        }
    }
    if(ans < cur) {
        ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
