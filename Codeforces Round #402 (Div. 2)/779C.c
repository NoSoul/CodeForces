#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m_Val[3];
} DataType_t;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val.m_Val[0] < array[now >> 1].m_Val[0]) {
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
        if((temp + 1) <= *len && array[temp + 1].m_Val[0] < array[temp].m_Val[0]) {
            ++temp;
        }
        if(array[temp].m_Val[0] < array[*len].m_Val[0]) {
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
    int n, k, len = 0;
    int A[200000];
    DataType_t B[200001], cur;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &cur.m_Val[1]);
        cur.m_Val[0] = cur.m_Val[1] - A[i];
        cur.m_Val[2] = i;
        BinaryHeapPush(B, &len, cur);
    }
    BinaryHeapSort(B, len);
    int Ans = 0;
    for(int i = 1; i <= k; ++i) {
        Ans += A[B[i].m_Val[2]];
    }
    for(int i = k + 1; i <= n; ++i) {
        if(B[i].m_Val[0] > 0) {
            Ans += A[B[i].m_Val[2]];
        } else {
            Ans += B[i].m_Val[1];
        }
    }
    printf("%d\n", Ans);
    return 0;
}
