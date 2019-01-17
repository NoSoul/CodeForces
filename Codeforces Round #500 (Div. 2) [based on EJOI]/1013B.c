#include <stdio.h>

typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val > array[now >> 1]) {
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

void BinaryHeapSort(DataType_t *array, int len)
{
    while(len) {
        int curIdx = len;
        array[curIdx] = BinaryHeapPop(array, &len);
    }
}

int main()
{
    int n, x;
    int a[100001];
    int b[100001];
    scanf("%d %d", &n, &x);
    int size = 0, num;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(a, &size, num);
    }
    BinaryHeapSort(a, size);
    for(int i = 2; i <= n; ++i) {
        if(a[i] == a[i - 1]) {
            puts("0");
            return 0;
        }
    }
    for(int i = 2; i <= n; ++i) {
        int expect = a[i] & x;
        int left = 1;
        int right = i - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(a[mid] == expect) {
                puts("1");
                return 0;
            } else if(a[mid] < expect) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    size = 0;
    for(int i = 1; i <= n; ++i) {
        BinaryHeapPush(b, &size, a[i]&x);
    }
    BinaryHeapSort(b, size);
    for(int i = 2; i <= n; ++i) {
        if(b[i] == b[i - 1]) {
            puts("2");
            return 0;
        }
    }
    puts("-1");
    return 0;
}
