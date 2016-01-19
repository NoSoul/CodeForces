#include <stdio.h>
#include <stdlib.h>

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
        if((temp + 1) <= *len && array[temp] < array[temp + 1]) {
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

int A[200001];

int BinaryFirstGreat(const int *array, int len, int key)
{
    int Left, Right, Mid;
    Left = 1;
    Right = len;
    while(Left < Right) {
        Mid = (Left + Right) / 2;
        if(array[Mid] <= key) {
            Left = Mid + 1;
        } else {
            Right = Mid;
        }
    }
    if(array[Left] <= key) {
        ++Left;
    }
    return Left - 1;
}

int main()
{
    int N, M, i, Num;
    while(scanf("%d %d", &N, &M) != EOF) {
        unsigned int len = 0;
        for(i = 0; i < N; ++i) {
            scanf("%d", &Num);
            BinaryHeapPush(A, &len, Num);
        }
        BinaryHeapSort(A, len);
        while(M--) {
            scanf("%d", &Num);
            printf("%d ", BinaryFirstGreat(A, N, Num));
        }
        puts("");
    }
    return 0;
}
