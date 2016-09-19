#include <stdio.h>

typedef int DataType_t;

void BinaryHeapPush(DataType_t *array, unsigned *len, DataType_t val)
{
    ++(*len);
    unsigned now = *len;
    while(now > 1 && val > array[now >> 1]) {
        array[now] = array[now >> 1];
        now >>= 1;
    }
    array[now] = val;
}

DataType_t BinaryHeapPop(DataType_t *array, unsigned *len)
{
    DataType_t ret = array[1];
    unsigned now = 1, temp;
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

void BinaryHeapSort(DataType_t *array, unsigned len)
{
    while(len) {
        unsigned curIdx = len;
        array[curIdx] = BinaryHeapPop(array, &len);
    }
}

int BinarySearch(int *array, int len, int key)
{
    int left = 0;
    int right = len;
    while(left < right) {
        int mid = (left + right) / 2;
        if(array[mid] >= key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int Data[100000];
unsigned Size;

int main()
{
    int n, x, q, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        BinaryHeapPush(Data, &Size, x);
    }
    BinaryHeapSort(Data, Size);
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &m);
        printf("%d\n", BinarySearch(Data + 1, Size, m + 1));
    }
    return 0;
}
