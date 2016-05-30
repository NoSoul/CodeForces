#include <stdio.h>

#define MAXN    100001
typedef struct {
    int s;
    int e;
} Seg_t;

Seg_t A[MAXN];
int Size;
char Str[MAXN];
int Dist[MAXN];

int BinarySearch(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;
    while(len < right - 1) {
        int mid = (left + right) / 2;
        if(array[mid] > key) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    while(left < len && array[left] <= key) {
        ++left;
    }
    return left - 1;
}

int main()
{
    int N, K, len, ans = 0;
    scanf("%d %d", &N, &K);
    scanf("%s", Str);
    for(int i = 0; i < 2; ++i) {
        len = 1;
        Size = 0;
        if(Str[0] == 'a') {
            A[Size].s = 0;
        }
        for(int j = 1; Str[j]; ++j) {
            if(Str[j] == 'a' && Str[j - 1] == 'b') {
                A[Size].s = j;
            }
            if(Str[j] == 'b' && Str[j - 1] == 'a') {
                A[Size].e = j - 1;
                ++Size;
            }
            ++len;
        }
        if(Str[len - 1] == 'a') {
            A[Size].e = len - 1;
            ++Size;
        }
        Dist[0] = 0;
        for(int j = 1; j < Size; ++j) {
            Dist[j] = Dist[j - 1] + A[j].s - A[j - 1].e-1;
        }
        for(int j = 0; j < Size; ++j) {
            int idx = j + BinarySearch(Dist + j, Size - j, Dist[j] + K);
            int cur = A[idx].e - A[j].s + 1;
            if(Dist[idx] - Dist[j] < K) {
                cur += K - Dist[idx] + Dist[j];
            }
            if(cur > N) {
                cur = N;
            }
            if(cur > ans) {
                ans = cur;
            }
        }
        for(int j = 0; Str[j]; ++j) {
            Str[j] = Str[j] == 'a' ? 'b' : 'a';
        }
    }
    printf("%d\n", ans);
    return 0;
}
