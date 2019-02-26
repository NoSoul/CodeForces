#include <stdio.h>
#include <math.h>

typedef struct {
    int idx;
    int val;
} DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    if(a.val == b.val) {
        return a.idx > b.idx ? 1 : 0;
    }
    return a.val < b.val ? 1 : 0;
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
    int n, t1, t2, k;
    scanf("%d %d %d %d", &n, &t1, &t2, &k);
    DataType_t Data[1001];
    int size = 0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int valA = (a * t1 * (100 - k) + b * t2 * 100);
        int valB = (b * t1 * (100 - k) + a * t2 * 100);
        DataType_t cur;
        cur.idx = i + 1;
        cur.val = valA > valB ? valA : valB;
        BinaryHeapPush(Data, &size, cur);
    }
    BinaryHeapSort(Data, size);
    for(int i = 1; i <= size; ++i) {
        printf("%d %d.%02d\n", Data[i].idx, Data[i].val / 100, Data[i].val % 100);
    }
    return 0;
}
