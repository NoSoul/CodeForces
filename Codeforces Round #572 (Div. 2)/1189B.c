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

int main()
{
    int a[100001];
    int b[100001];
    int size = 0, n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(a, &size, num);
    }
    BinaryHeapSort(a, size);
    b[0] = a[1];
    int i = 1;
    int j = n - 1;
    int idx = 2;
    while(1) {
        b[i++] = a[idx++];
        if(idx == n + 1) {
            break;
        }
        b[j--] = a[idx++];
        if(idx == n + 1) {
            break;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(b[i] >= b[(i - 1 + n) % n] + b[(i + 1) % n]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i = 0; i < n; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
