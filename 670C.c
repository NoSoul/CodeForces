#include <stdio.h>

#define MAXN    200001
typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, unsigned int *len, DataType_t val)
{
    ++(*len);
    unsigned int now = *len;
    while(now > 1 && val > array[now >> 1]) {
        array[now] = array[now >> 1];
        now >>= 1;
    }
    array[now] = val;
}

DataType_t BinaryHeapPop(DataType_t *array, unsigned int *len)
{
    DataType_t ret = array[1];
    unsigned int now = 1, temp;
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

void BinaryHeapSort(DataType_t *array, unsigned int len)
{
    while(len) {
        unsigned int curIdx = len;
        array[curIdx] = BinaryHeapPop(array, &len);
    }
}

typedef struct {
    int val;
    int cnt;
} Node_t;

Node_t Data[MAXN];
int A[MAXN];
int B[MAXN];
int C[MAXN];

int GetNum(Node_t *array, int len, int key)
{
    int left = 0;
    int right = len - 1;
    while(left < right) {
        int mid = (left + right) / 2;
        if(array[mid].val == key) {
            return array[mid].cnt;
        } else if(array[mid].val < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(array[left].val == key) {
        return array[left].cnt;
    }
    return 0;
}

int main()
{
    int N, i, M, a;
    unsigned int j, len = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &len, a);
    }
    BinaryHeapSort(A, len);
    int Size = 0;
    Data[Size].val = A[1];
    Data[Size].cnt = 1;
    for(j = 2; j <= len; ++j) {
        if(A[j] != Data[Size].val) {
            ++Size;
            Data[Size].val = A[j];
            Data[Size].cnt = 1;
        } else {
            ++Data[Size].cnt;
        }
    }
    ++Size;
    scanf("%d", &M);
    for(i = 0; i < M; ++i) {
        scanf("%d", &B[i]);
    }
    for(i = 0; i < M; ++i) {
        scanf("%d", &C[i]);
    }
    int maxPleased = 0;
    int maxSatisfied = 0;
    int ans = 1;
    for(i = 0; i < M; ++i) {
        int pleased = GetNum(Data, Size, B[i]);
        int satisfied = GetNum(Data, Size, C[i]);
        if(pleased > maxPleased || (pleased == maxPleased && satisfied > maxSatisfied)) {
            maxPleased = pleased;
            maxSatisfied = satisfied;
            ans = i + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
