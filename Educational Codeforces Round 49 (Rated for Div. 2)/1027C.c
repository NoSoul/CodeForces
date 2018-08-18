#include <stdio.h>
#include <string.h>

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
int A[1000001];

int main()
{
    int T;
    int Cnt[10001];
    scanf("%d", &T);
    while(T--) {
        int n, a;
        scanf("%d", &n);
        int len = 0;
        memset(Cnt, 0, sizeof(Cnt));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ++Cnt[a];
            BinaryHeapPush(A, &len, a);
        }
        int Data[10001];
        int Size = 0;
        char find = 0;
        if(n < 10001) {
            BinaryHeapSort(A, len);
            for(int i = 1; i <= n; ++i) {
                if(i + 3 <= n && A[i + 3] == A[i]) {
                    printf("%d %d %d %d\n", A[i], A[i], A[i], A[i]);
                    find = 1;
                    break;
                } else if(i + 1 <= n && A[i + 1] == A[i]) {
                    Data[Size++] = A[i];
                    int cur = i;
                    while(i + 1 <= n && A[i + 1] == A[cur]) {
                        ++i;
                    }
                }
            }
        } else {
            for(int i = 1; i < 10001; ++i) {
                if(Cnt[i] >= 4) {
                    printf("%d %d %d %d\n", i, i, i, i);
                    find = 1;
                    break;
                } else if(Cnt[i] >= 2) {
                    Data[Size++] = A[i];
                }

            }
        }
        if(!find) {
            int ansI, ansJ;
            for(int i = 0; i < Size - 1; ++i) {
                if(!find) {
                    find = 1;
                    ansI = Data[i];
                    ansJ = Data[i + 1];
                } else if((long long)(Data[i] + Data[i + 1]) * (Data[i] + Data[i + 1]) * (ansI * ansJ) < (long long)(ansI + ansJ) * (ansI + ansJ) * (Data[i] * Data[i + 1])) {
                    ansI = Data[i];
                    ansJ = Data[i + 1];
                }
            }
            printf("%d %d %d %d\n", ansI, ansI, ansJ, ansJ);
        }
    }
    return 0;
}
