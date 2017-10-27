#include <stdio.h>

int A[100001];
unsigned int Size;

int Ans[100001];
int Cnt;
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

int main()
{
    int N, M, i, a;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%d", &a);
        BinaryHeapPush(A, &Size, a);
    }
    BinaryHeapSort(A, Size);
    int start = 1;
    int end = A[1];
    unsigned int j = 1;
    char flag = 0;
    while(1) {
        for(i = start; i < end; ++i) {
            if(M >= i) {
                M -= i;
                Ans[Cnt++] = i;
            } else {
                flag = 1;
                break;
            }
        }
        start = A[j] + 1;
        ++j;
        if(j > Size) {
            end = 0x7fffffff;
        } else {
            end = A[j];
        }
        if(flag) {
            break;
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i) {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
