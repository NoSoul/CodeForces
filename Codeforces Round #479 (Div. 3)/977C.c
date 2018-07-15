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

int Data[200001];

int main()
{
    int n, k, a;
    scanf("%d %d", &n, &k);
    int len = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(Data, &len, a);
    }
    BinaryHeapSort(Data, len);
    if(k == 0) {
        printf("%d\n", Data[1] == 1 ? -1 : 1);
    } else {
        printf("%d\n", Data[k + 1] == Data[k] ? -1 : Data[k]);
    }
    return 0;
}
