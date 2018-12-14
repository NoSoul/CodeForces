#include <stdio.h>

typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val < array[now >> 1]) {
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
        if((temp + 1) <= *len && array[temp + 1] < array[temp]) {
            ++temp;
        }
        if(array[temp] < array[*len]) {
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

int A[100001], B[100001];
int SizeA, SizeB;

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &SizeA, a);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b);
        BinaryHeapPush(B, &SizeB, b);
    }
    BinaryHeapSort(A, SizeA);
    BinaryHeapSort(B, SizeB);
    int i = 1, j = 1;
    long long sumA = 0, sumB = 0;
    while(i <= n || j <= n) {
        if((B[j] > A[i] && i <= n && j <= n) || i > n) {
            ++j;
        } else if(i <= n) {
            sumA += A[i];
            ++i;
        }

        if((A[i] > B[j] && i <= n && j <= n) || j > n) {
            ++i;
        } else if(j <= n) {
            sumB += B[j];
            ++j;
        }
    }
    printf("%I64d\n", sumA - sumB);
    return 0;
}
