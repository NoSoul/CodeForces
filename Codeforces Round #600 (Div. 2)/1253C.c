#include <stdio.h>

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

DataType_t A[200001];
long long Delta[200001];

int main()
{
    int n, m, num;
    int size = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(A, &size, num);
    }
    BinaryHeapSort(A, size);
    for(int i = 1; i <= m; ++i) {
        Delta[i] = A[i];
    }
    for(int i = m + 1; i <= n; ++i) {
        Delta[i] = A[i] + Delta[i - m];
    }
    long long last = 0;
    for(int i = 1; i <= n; ++i) {
        long long ans = 0;
        ans = last + Delta[i];
        last = ans;
        printf("%I64d\n", ans);
    }
    return 0;
}
