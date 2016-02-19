#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point_t;

long long GetDistance(Point_t a, Point_t b)
{
    return (long long)(a.x - b.x) * (a.x - b.x) + (long long)(a.y - b.y) * (a.y - b.y);
}

typedef struct {
    long long d0;
    long long d1;
} Node_t;
Node_t Distance[2001];
typedef Node_t DataType_t;

void BinaryHeapPush(DataType_t *array, unsigned int *len, DataType_t val)
{
    ++(*len);
    unsigned int now = *len;
    while(now > 1 && val.d0 > array[now >> 1].d0) {
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
        if((temp + 1) <= *len && array[temp].d0 < array[temp + 1].d0) {
            ++temp;
        }
        if(array[temp].d0 > array[*len].d0) {
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
    int N, i, j;
    long long R1, R2, Ans;
    Point_t Fountains[2];
    Point_t Flowers;
    while(scanf("%d", &N) != EOF) {
        for(i = 0; i < 2; ++i) {
            scanf("%d %d", &Fountains[i].x, &Fountains[i].y);
        }
        Node_t temp;
        unsigned int Size = 0;
        for(i = 0; i < N; ++i) {
            scanf("%d %d", &Flowers.x, &Flowers.y);
            temp.d0 = GetDistance(Flowers, Fountains[0]);
            temp.d1 = GetDistance(Flowers, Fountains[1]);
            BinaryHeapPush(Distance, &Size, temp);
        }
        BinaryHeapSort(Distance, Size);
        Ans = 0;
        for(i = 1; i <= N; ++i) {
            if(Distance[i].d1 > Ans) {
                Ans = Distance[i].d1;
            }
        }
        for(i = 1; i <= N; ++i) {
            R1 = Distance[i].d0;
            R2 = 0;
            for(j = i + 1; j <= N; ++j) {
                if(Distance[j].d1 > R2) {
                    R2 = Distance[j].d1;
                }
            }
            if(R1 + R2 < Ans) {
                Ans = R1 + R2;
            }
        }
        printf("%I64d\n", Ans);
    }
    return 0;
}
