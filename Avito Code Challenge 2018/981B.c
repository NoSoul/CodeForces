#include <stdio.h>

typedef struct {
    int m_Idx;
    int m_Val;
} Node_t;

typedef Node_t DataType_t;

int Max(DataType_t a, DataType_t b)
{
    if(a.m_Idx == b.m_Idx) {
        return a.m_Val > b.m_Val;
    }
    return a.m_Idx > b.m_Idx;
}

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && Max(val, array[now >> 1])) {
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
        if((temp + 1) <= *len && Max(array[temp + 1], array[temp])) {
            ++temp;
        }
        if(Max(array[temp], array[*len])) {
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

Node_t A[200001];
int Size;

int main()
{
    int n;
    Node_t temp;
    for(int i = 0; i < 2; ++i) {
        scanf("%d", &n);
        for(int j = 0; j < n; ++j) {
            scanf("%d %d", &temp.m_Idx, &temp.m_Val);
            BinaryHeapPush(A, &Size, temp);
        }
    }
    BinaryHeapSort(A, Size);
    long long ans = 0;
    for(int i = 1; i <= Size; ++i) {
        if(i + 1 <= Size && A[i + 1].m_Idx == A[i].m_Idx) {
            ans += A[i + 1].m_Val;
            ++i;
        } else {
            ans += A[i].m_Val;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
