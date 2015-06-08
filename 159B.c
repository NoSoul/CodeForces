#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int x, y;
} Item;
Item Temp[MAX];

typedef struct {
    Item p;
    int cnt;
} Point;
Point Marker[MAX], Cap[MAX];
int N, M;

int cmp(const void *a, const void *b)
{
    if((*(Item *)a).y == (*(Item *)b).y) {
        return (*(Item *)a).x - (*(Item *)b).x;
    }
    return (*(Item *)a).y - (*(Item *)b).y;
}

int Init(Point *A, int n)
{
    int i, Cnt = 0;
    for(i = 0; i < n; ++i) {
        scanf("%d %d", &Temp[i].x, &Temp[i].y);
    }
    qsort(Temp, n, sizeof(Item), cmp);
    A[Cnt].p = Temp[0];
    A[Cnt].cnt = 1;
    for(i = 1; i < n; ++i) {
        if(Temp[i].x == A[Cnt].p.x && Temp[i].y == A[Cnt].p.y) {
            ++A[Cnt].cnt;
        } else {
            ++Cnt;
            A[Cnt].p = Temp[i];
            A[Cnt].cnt = 1;
        }
    }
    return Cnt + 1;
}

int Binary_Item(Item key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = M - 1;
    while(Left <= Right) {
        Mid = (Left + Right) >> 1;
        if(Cap[Mid].p.y < key.y) {
            Left = Mid + 1;
        } else if(Cap[Mid].p.y > key.y) {
            Right = Mid - 1;
        } else {
            if(Cap[Mid].p.x == key.x) {
                return Mid;
            } else if(Cap[Mid].p.x < key.x) {
                Left = Mid + 1;
            } else {
                Right = Mid - 1;
            }
        }
    }
    return -1;
}

int Binary_y(int key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = M - 1;
    while(Left <= Right) {
        Mid = (Left + Right) >> 1;
        if(Cap[Mid].p.y >= key) {
            Right = Mid - 1;
        } else {
            Left = Mid + 1;
        }
    }
    return Left;
}

int main()
{
    int i, j, k, Cnt, Max;
    scanf("%d %d", &N, &M);
    N = Init(Marker, N);
    M = Init(Cap, M);
    for(Cnt = Max = i = 0; i < N; ++i) {
        j = Binary_Item(Marker[i].p);
        if(j != -1) {
            k = Marker[i].cnt < Cap[j].cnt ? Marker[i].cnt : Cap[j].cnt;
            if(k) {
                Cnt += k;
                Max += k;
                Marker[i].cnt -= k;
                Cap[j].cnt -= k;
            }
        }
    }
    for(i = 0; i < N; ++i) {
        while(Marker[i].cnt--) {
            j = Binary_y(Marker[i].p.y);
            for(k = j; Marker[i].p.y == Cap[k].p.y; ++k) {
                if(Cap[k].cnt) {
                    --Cap[k].cnt;
                    ++Cnt;
                    break;
                }
            }
        }
    }
    printf("%d %d\n", Cnt, Max);
    return 0;
}
