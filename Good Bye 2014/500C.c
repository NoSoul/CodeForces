#include <stdio.h>

#define MAXN    500
#define MAXM    1000

unsigned char Visited[MAXN];

int main()
{
    int N, M, i, j, Ans, Size, Sum;
    int A[MAXN], B[MAXM];
    int Stack[MAXN];
    Size = Ans = Sum = 0;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < M; ++i) {
        scanf("%d", &B[i]);
        --B[i];
        if(!Visited[B[i]]) {
            Visited[B[i]] = 1;
            Ans += Sum;
            Stack[Size++] = B[i];
            Sum += A[B[i]];
        } else {
            int temp = 0;
            for(j = Size - 1; j >= 0; --j) {
                if(Stack[j] == B[i]) {
                    break;
                }
                temp += A[Stack[j]];
            }
            Ans += temp;
            for(; j < Size - 1; ++j) {
                Stack[j] = Stack[j + 1];
            }
            Stack[Size - 1] = B[i];
        }
    }
    printf("%d\n", Ans);
    return 0;
}
