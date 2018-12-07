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

DataType_t A[200001];

int main()
{
    int n, s, a, size = 0;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &size, a);
    }
    BinaryHeapSort(A, size);
    int pos = (n + 1) / 2;
    if(A[pos] == s) {
        puts("0");
    } else if(A[pos] > s) {
        long long ans = 0;
        ans += A[pos] - s;
        for(int i = pos - 1; i > 0; --i) {
            if(A[i] > s) {
                ans += A[i] - s;
            }
        }
        printf("%I64d\n", ans);
    } else {
        long long ans = 0;
        ans += s - A[pos];
        for(int i = pos + 1; i <= n; ++i) {
            if(A[i] < s) {
                ans += s - A[i];
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
