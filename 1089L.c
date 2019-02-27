#include <stdio.h>

typedef struct {
    int idx;
    int val;
} DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    return a.val > b.val ? 1 : 0;
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

int Cnt[100001];

int main()
{
    int n, k;
    int A[100000];
    DataType_t Data[100001];
    int size = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        ++Cnt[A[i]];
    }
    for(int i = 0; i < n; ++i) {
        DataType_t cur;
        scanf("%d", &cur.val);
        cur.idx = i;
        BinaryHeapPush(Data, &size, cur);
    }
    int remain = 0;
    for(int i = 1; i <= k; ++i) {
        if(Cnt[i] == 0) {
            ++remain;
        }
    }
    BinaryHeapSort(Data, size);
    long long ans = 0;
    if(remain) {
        for(int i = 1; i <= n; ++i) {
            if(Cnt[A[Data[i].idx]] > 1) {
                --Cnt[A[Data[i].idx]];
                ans += Data[i].val;
                if(--remain == 0) {
                    break;
                }
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
