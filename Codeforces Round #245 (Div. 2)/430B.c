#include <stdio.h>
#include <string.h>

int Destroy(int *Data, int Len)
{
    int i, j;
    int Pre = Data[0];
    int Con = 1;
    for(i = 1; i < Len; ++i) {
        if(Data[i] == Pre) {
            ++Con;
        } else {
            if(Con > 2) {
                for(j = i - Con; j < Len - Con; ++j) {
                    Data[j] = Data[j + Con];
                }
                return Con + Destroy(Data, Len - Con);
            } else {
                Pre = Data[i];
                Con = 1;
            }
        }
    }
    if(Con > 2) {
        return Con + Destroy(Data, Len - Con);
    }
    return 0;
}

int Fun(int *Data, int Len, int idx)
{
    int Array[101];
    memcpy(Array, Data, idx * sizeof(int));
    Array[idx] = Data[idx - 1];
    memcpy(Array + idx + 1, Data + idx, (Len - idx)*sizeof(int));
    return Destroy(Array, Len + 1);
}

int main()
{
    int N, K, X, i, Max, Sum;
    int Data[101];
    scanf("%d %d %d", &N, &K, &X);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Data[i]);
    }
    Max = 0;
    for(i = 0; i < N; ++i) {
        if(Data[i] == X && i > 0 && Data[i - 1] == X) {
            Sum = Fun(Data, N, i + 1) - 1;
            if(Sum > Max) {
                Max = Sum;
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
