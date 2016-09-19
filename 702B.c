#include <stdio.h>

#define MAXN    100000

int Data[MAXN];
typedef struct {
    int m_Num;
    int m_Cnt;
} Node_t;
Node_t Array[MAXN];
unsigned Size;
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

int BinarySearch(Node_t *a, unsigned size, int key)
{
    unsigned left = 0;
    unsigned right = size - 1;
    while(left < right) {
        unsigned mid = (left + right) >> 1;
        if(a[mid].m_Num == key) {
            return a[mid].m_Cnt;
        } else if(a[mid].m_Num > key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if(a[left].m_Num == key) {
        return a[left].m_Cnt;
    }
    return 0;
}

int main()
{
    int N, num;
    long long Ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &num);
        BinaryHeapPush(Data, &Size, num);
    }
    BinaryHeapSort(Data, Size);
    Size = 0;
    Array[Size].m_Num = Data[1];
    Array[Size].m_Cnt = 1;
    for(int i = 2; i <= N; ++i) {
        if(Data[i] == Array[Size].m_Num) {
            ++Array[Size].m_Cnt;
        } else {
            ++Size;
            Array[Size].m_Num = Data[i];
            Array[Size].m_Cnt = 1;
        }
    }
    ++Size;
    for(int i = 0; i < Size; ++i) {
        for(int j = 0; j < 32; ++j) {
            unsigned target = 1 << j;
            if((unsigned)(Array[i].m_Num << 1) > target) {
                continue;
            }
            if((unsigned)(Array[i].m_Num << 1) == target) {
                Ans += (long long)Array[i].m_Cnt * (Array[i].m_Cnt - 1) / 2;
            } else {
                if(target - Array[i].m_Num <= Array[Size - 1].m_Num) {
                    int num = BinarySearch(Array, Size, target - Array[i].m_Num);
                    Ans += (long long)Array[i].m_Cnt * num;
                }
            }
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
