#include <stdio.h>

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

int A[1001];
unsigned Size;

int main()
{
    int N, num;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(A, &Size, num);
    }
    BinaryHeapSort(A, Size);
    int i = 1;
    int j = Size;
    for(int k = 0; k < N; ++k) {
        if(k & 1) {
            printf("%d ", A[j--]);
        } else {
            printf("%d ", A[i++]);
        }
    }
    puts("");
    return 0;
}
