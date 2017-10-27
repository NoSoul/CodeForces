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

int A[100001];

void Update(int *a, int *b, int *c, int num)
{
    int *min = a;
    if(*min > *b) {
        min = b;
    }
    if(*min > *c) {
        min = c;
    }
    *min += num;
}

int main()
{
    int N, i, num;
    unsigned j, len = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(A, &len, num);
    }
    BinaryHeapSort(A, len);
    int B[3];
    B[0] = A[len];
    B[1] = A[len - 1];
    B[2] = A[len - 2];
    for(j = len - 3; j >= 1; --j) {
        Update(&B[0], &B[1], &B[2], A[j]);
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = i; j < 3; ++j) {
            if(B[j] > B[i]) {
                int temp = B[j];
                B[j] = B[i];
                B[i] = temp;
            }
        }
    }
    printf("%d\n", B[0] - B[1] - B[2] + 1);
    return 0;
}
