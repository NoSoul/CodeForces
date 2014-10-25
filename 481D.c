#include <stdio.h>

#define MAXN    200000
typedef struct
{
    long long a;
    int id;
} Server_t;
Server_t BinLow[MAXN+1];
Server_t Low[MAXN];
Server_t BinHig[MAXN+1];
Server_t Hig[MAXN];
long long SumLow[MAXN];
long long SumHig[MAXN];
int SizeLow, SizeHig;

long long A[MAXN+1];
int SizeA, SizeB, SizeC;

void Binary_Heap_Push0(long long x)
{
    int Now;
    Now = ++SizeA;
    while(Now>1 && x>A[Now>>1])
    {
        A[Now] = A[Now>>1];
        Now >>= 1;
    }
    A[Now] = x;
    return;
}

long long Binary_Heap_Pop0()
{
    int Min, Now, temp;
    long long res = A[1];
    Now = 1;
    while((Now<<1) <= SizeA)
    {
        temp = Now<<1;
        if((temp+1)<=SizeA && A[temp]<A[temp+1])
        {
            ++temp;
        }
        if(A[temp] > A[SizeA])
        {
            A[Now] = A[temp];
        }
        else
        {
            break;
        }
        Now = temp;
    }
    A[Now] = A[SizeA];
    --SizeA;
    return res;
}

void Binary_Heap_Push1(Server_t *Binary_Heap, int *Size, long long x, int id)
{
    int Now;
    Now = ++(*Size);
    while(Now>1 && x>Binary_Heap[Now>>1].a)
    {
        Binary_Heap[Now] = Binary_Heap[Now>>1];
        Now >>= 1;
    }
    Binary_Heap[Now].a = x;
    Binary_Heap[Now].id = id;
    return;
}

Server_t Binary_Heap_Pop1(Server_t *Binary_Heap, int *Size)
{
    int Min, Now, temp;
    Server_t res = Binary_Heap[1];
    Now = 1;
    while((Now<<1) <= (*Size))
    {
        temp = Now<<1;
        if((temp+1)<=(*Size) && Binary_Heap[temp].a<Binary_Heap[temp+1].a)
        {
            ++temp;
        }
        if(Binary_Heap[temp].a > Binary_Heap[*Size].a)
        {
            Binary_Heap[Now] = Binary_Heap[temp];
        }
        else
        {
            break;
        }
        Now = temp;
    }
    Binary_Heap[Now] = Binary_Heap[*Size];
    --(*Size);
    return res;
}


int main()
{
    int N, i, l, R, W;
    long long M, Sum, num;
    scanf("%d %I64d", &N, &M);
    SumLow[0] = 0;
    SumHig[0] = 0;
    for(i=0; i<N; ++i)
    {
        scanf("%I64d %d", &num, &l);
        Binary_Heap_Push0(num);
        if(l == 1)
        {
            Binary_Heap_Push1(BinLow, &SizeB, num, i+1);
            SumLow[0] += num;
        }
        else
        {
            Binary_Heap_Push1(BinHig, &SizeC, num, i+1);
            SumHig[0] += num;
        }
    }
    Sum = 0;
    for(i=0; i<N; ++i)
    {
        Sum += Binary_Heap_Pop0();
        if(Sum >= M)
        {
            R = i + 1;
            break;
        }
    }
    SizeLow = SizeB;
    SizeHig = SizeC;
    for(i=0; i<SizeLow; ++i)
    {
        Low[i] = Binary_Heap_Pop1(BinLow, &SizeB);
    }
    for(i=0; i<SizeHig; ++i)
    {
        Hig[i] = Binary_Heap_Pop1(BinHig, &SizeC);
    }
    for(i=1; i<SizeLow; ++i)
    {
        SumLow[i] = SumLow[i-1] - Low[i-1].a;
    }
    for(i=1; i<SizeHig; ++i)
    {
        SumHig[i] = SumHig[i-1] - Hig[i-1].a;
    }
    W = R;
    if(W > SizeLow)
    {
        W = SizeLow;
    }
    for(; W>=0; --W)
    {
        int Remain = R - W;
        long long LowS, HigS;
        if(W == SizeLow)
        {
            LowS = SumLow[0];
        }
        else
        {
            LowS = SumLow[0] - SumLow[W];
        }
        if(Remain == SizeHig)
        {
            HigS = SumHig[0];
        }
        else
        {
            HigS = SumHig[0] - SumHig[Remain];
        }
        if(LowS + HigS >= M)
        {
            break;
        }
    }
    printf("%d %d\n", R, W);
    for(i=0; i<W; ++i)
    {
        printf("%d ", Low[i].id);
    }
    for(i=0; i<R-W; ++i)
    {
        printf("%d ", Hig[i].id);
    }
    puts("");
    return 0;
}
