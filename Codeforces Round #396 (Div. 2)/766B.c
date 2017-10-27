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

int BinarySearchLT(int *array, int len, int val)
{
    int left = 0;
    int right = len - 1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(array[mid] < val) {
            return 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int n, num, len = 0;
    int a[100001];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(a, &len, num);
    }
    BinaryHeapSort(a, len);
    for(int i = 1; i <= n - 2; ++i) {
        int sum = a[i] + a[i + 1];
        if(BinarySearchLT(a + i + 2,  n - 1 - i, sum)) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
