#include <stdio.h>

typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val< array[now >> 1]) {
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

int S[100001];

int main()
{
    int n, A, B, size = 0, First;
    scanf("%d %d %d", &n, &A, &B);
    int pos = 1, sum = 0;
    scanf("%d", &First);
    sum += First;
    for(int i = 1; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        sum += temp;
        BinaryHeapPush(S, &size, temp);
    }
    BinaryHeapSort(S, size);
    int ans = 0;
    for(int i = 1; i <= size; ++i) {
        if((long long)First * A >= (long long)B * sum) {
            printf("%d\n", ans);
            return 0;
        } else {
            ++ans;
            sum -= S[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
