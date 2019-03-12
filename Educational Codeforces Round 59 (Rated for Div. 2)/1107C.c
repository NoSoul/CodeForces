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

int A[200001];
int B[200001];
char Hits[200001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%s", Hits);
    int curLen = 1;
    long long curSum = A[0];
    int size = 0;
    BinaryHeapPush(B, &size, A[0]);
    for(int i = 1; Hits[i]; ++i) {
        if(Hits[i] == Hits[i - 1]) {
            BinaryHeapPush(B, &size, A[i]);
            curSum += A[i];
            ++curLen;
        } else {
            if(curLen <= k) {
                ans += curSum;
            } else {
                BinaryHeapSort(B, size);
                for(int j = 1; j <= k; ++j) {
                    ans += B[j];
                }
            }
            curLen = 1;
            curSum = A[i];
            size = 0;
            BinaryHeapPush(B, &size, A[i]);
        }
    }
    if(curLen <= k) {
        ans += curSum;
    } else {
        BinaryHeapSort(B, size);
        for(int j = 1; j <= k; ++j) {
            ans += B[j];
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
