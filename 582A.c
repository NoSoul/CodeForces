#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int cnt;
} Node_t;
Node_t B[250000];
int Size;
int Ans[500];
int AnsSize;

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)b).num - (*(Node_t *)a).num;
}

int GCD(int a, int b)
{
    int temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int BinarySearch(Node_t *array, int len, int key)
{
    int left = 0;
    int right = len - 1;
    while(left < right) {
        int mid = (left + right) >> 1;
        if(array[mid].num == key) {
            return mid;
        } else if(array[mid].num < key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N * N; ++i) {
        scanf("%d", &B[i].num);
    }
    qsort(B, N * N, sizeof(Node_t), cmp);
    ++Size;
    B[Size - 1].cnt = 1;
    for(i = 1; i < N * N; ++i) {
        if(B[i].num == B[Size - 1].num) {
            ++B[Size - 1].cnt;
        } else {
            ++Size;
            B[Size - 1].num = B[i].num;
            B[Size - 1].cnt = 1;
        }
    }
    for(i = 0; i < Size; ++i) {
        while(B[i].cnt) {
            --B[i].cnt;
            for(j = 0; j < AnsSize; ++j) {
                int num = GCD(Ans[j], B[i].num);
                int idx = BinarySearch(B, Size, num);
                B[idx].cnt -= 2;
            }
            Ans[AnsSize++] = B[i].num;
        }
    }
    for(i = AnsSize - 1; i >= 0; --i) {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
