#include <stdio.h>

typedef int DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    return a < b ? 1 : 0;
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

DataType_t Data[300001];

int main()
{
    int n, a;
    long long sum = 0;
    scanf("%d", &n);
    int size = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        BinaryHeapPush(Data, &size, a);
    }
    BinaryHeapSort(Data, size);
    int m, q;
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &q);
        printf("%I64d\n", sum - Data[q]);
    }
    return 0;
}
