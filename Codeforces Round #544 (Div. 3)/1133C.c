#include <stdio.h>
#include <stdlib.h>

typedef int DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    return a > b ? 1 : 0;
}

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && DataCMP(val, array[now >> 1])) {
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
        if((temp + 1) <= *len && DataCMP(array[temp + 1], array[temp])) {
            ++temp;
        }
        if(DataCMP(array[temp], array[*len])) {
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
    int n, a;
    int A[200001];
    int Size = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &Size, a);
    }
    BinaryHeapSort(A, Size);
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        int expectKey = A[i] + 5;
        int left = i + 1;
        int right = n;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(A[mid] > expectKey) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(ans < left - i) {
            ans = left - i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
