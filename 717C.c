#include <stdio.h>

#define MOD 10007

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

int main()
{
    int n, num;
    int a[100001], size = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(a, &size, num);
    }
    BinaryHeapSort(a, size);
    int ans = 0;
    for(int i = 1, j = n; i <= j; ++i, --j) {
        if(i == j) {
            ans = (ans + (a[i] % MOD * a[i] % MOD) % MOD) % MOD;
        } else {
            ans = (ans + (a[i] % MOD * a[j] % MOD) % MOD) % MOD;
            ans = (ans + (a[i] % MOD * a[j] % MOD) % MOD) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
