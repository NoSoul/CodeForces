#include <stdio.h>

int A[100000];
char Flag[100000];

int main()
{
    int N, K, id;
    long long Ans = 0, Sum = 0, Add = 0;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        Sum += A[i];
    }
    Ans = (long long)A[0] * A[N - 1];
    for(int i = 0; i < N - 1; ++i) {
        Ans += (long long)A[i] * A[i + 1];
    }
    while(K--) {
        scanf("%d", &id);
        --id;
        int pre = (id - 1 + N) % N;
        int next = (id + 1 + N) % N;
        Ans += (long long)(Sum - A[pre] - A[next] - A[id]) * A[id];
        int reamin = 0;
        if(Flag[pre]) {
            reamin += A[pre];
        }
        if(Flag[next]) {
            reamin += A[next];
        }
        Ans -= (Add - reamin) * A[id];
        Add += A[id];
        Flag[id] = 1;
    }
    printf("%I64d\n", Ans);
    return 0;
}
