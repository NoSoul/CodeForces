#include <stdio.h>
#include <stdlib.h>

#define MAXN    100001
typedef struct {
    long long val;
    char ch;
    int idx;
} Node_t;
Node_t A[MAXN];
int Data[26];

int cmp(const void *a, const void *b)
{
    if((*(Node_t *)a).val == (*(Node_t *)b).val) {
        if((*(Node_t *)a).ch == (*(Node_t *)b).ch) {
            return (*(Node_t *)a).idx > (*(Node_t *)b).idx ? 1 : -1;
        }
        return (*(Node_t *)a).ch > (*(Node_t *)b).ch ? 1 : -1;
    }
    return (*(Node_t *)a).val > (*(Node_t *)b).val ? 1 : -1;
}

int BinarySearchFirst(Node_t *array, int len, Node_t key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = len - 1;
    while(Left < Right) {
        Mid = (Left + Right) >> 1;
        if(array[Mid].val < key.val) {
            Left = Mid + 1;
        } else if(array[Mid].val > key.val) {
            Right = Mid - 1;
        } else {
            if(array[Mid].ch < key.ch) {
                Left = Mid + 1;
            } else if(array[Mid].ch > key.ch) {
                Right = Mid - 1;
            } else {
                if(array[Mid].idx <= key.idx) {
                    Left = Mid + 1;
                } else {
                    Right = Mid;
                }
            }
        }
    }
    if(array[Left].val == key.val && array[Left].ch == key.ch && array[Left].idx > key.idx) {
        return Left;
    }
    return -1;
}

int BinarySearchLast(Node_t *array, int len, Node_t key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = len - 1;
    while(Left < Right) {
        Mid = (Left + Right) >> 1;
        if(array[Mid].val < key.val) {
            Left = Mid + 1;
        } else if(array[Mid].val > key.val) {
            Right = Mid - 1;
        } else {
            if(array[Mid].ch < key.ch) {
                Left = Mid + 1;
            } else if(array[Mid].ch > key.ch) {
                Right = Mid - 1;
            } else {
                Left = Mid + 1;
            }
        }
    }
    if(array[Left].val == key.val && array[Left].ch == key.ch && array[Left].idx > key.idx) {
        return Left;
    }
    --Left;
    if(~Left) {
        if(array[Left].val == key.val && array[Left].ch == key.ch && array[Left].idx > key.idx) {
            return Left;
        }
    }
    return -1;
}

int main()
{
    int i, Len;
    long long Ans = 0;
    char Str[MAXN];
    for(i = 0; i < 26; ++i) {
        scanf("%d", &Data[i]);
    }
    scanf("%s", Str);
    for(i = Len = 0; Str[i] != '\0'; ++i, ++Len) {
        A[i].val = Data[Str[i] - 'a'];
        if(i) {
            A[i].val += A[i - 1].val;
        }
        A[i].ch = Str[i];
        A[i].idx = i;
    }
    qsort(A, Len, sizeof(Node_t), cmp);
    for(i = 0; i < Len; ++i) {
        Node_t key;
        key.val = A[i].val + Data[A[i].ch - 'a'];
        key.ch = A[i].ch;
        key.idx = A[i].idx;
        int beg = BinarySearchFirst(A, Len, key);
        if(~beg) {
            int end = BinarySearchLast(A, Len, key);
            Ans += end - beg + 1;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
