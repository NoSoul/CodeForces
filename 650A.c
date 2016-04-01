#include <stdio.h>

typedef struct {
    int x, y;
} Point_t;
Point_t A[200001];
Point_t Data[200001];

int IsBigger(Point_t a, Point_t b)
{
    if(a.x > b.x) {
        return 1;
    }
    if(a.x == b.x && a.y > b.y) {
        return 1;
    }
    return 0;
}

typedef Point_t DataType_t;
void BinaryHeapPush(DataType_t *array, unsigned int *len, DataType_t val)
{
    ++(*len);
    unsigned int now = *len;
    while(now > 1 && IsBigger(val, array[now >> 1])) {
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
        if((temp + 1) <= *len && IsBigger(array[temp + 1], array[temp])) {
            ++temp;
        }
        if(IsBigger(array[temp], array[*len])) {
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
    int N, i, temp;
    unsigned int Size = 0;
    long long Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].x, &A[i].y);
        BinaryHeapPush(Data, &Size, A[i]);
    }
    BinaryHeapSort(Data, Size);
    int pre, cnt;
    pre = Data[1].x;
    cnt = 1;
    for(int i = 2; i <= N; ++i) {
        if(Data[i].x == pre) {
            ++cnt;
        } else {
            Ans += (long long)cnt * (cnt - 1) / 2;
            pre = Data[i].x;
            cnt = 1;
        }
    }
    Ans += (long long)cnt * (cnt - 1) / 2;
    Size = 0;
    for(i = 0; i < N; ++i) {
        temp = A[i].x;
        A[i].x = A[i].y;
        A[i].y = temp;
        BinaryHeapPush(Data, &Size, A[i]);
    }
    BinaryHeapSort(Data, Size);
    pre = Data[1].x;
    cnt = 1;
    for(int i = 2; i <= N; ++i) {
        if(Data[i].x == pre) {
            ++cnt;
        } else {
            Ans += (long long)cnt * (cnt - 1) / 2;
            pre = Data[i].x;
            cnt = 1;
        }
    }
    Ans += (long long)cnt * (cnt - 1) / 2;
    cnt = 1;
    for(int i = 2; i <= N; ++i) {
        if(Data[i].x == Data[i - 1].x && Data[i].y == Data[i - 1].y) {
            ++cnt;
        } else {
            Ans -= (long long)cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    Ans -= (long long)cnt * (cnt - 1) / 2;
    printf("%I64d\n", Ans);
    return 0;
}
