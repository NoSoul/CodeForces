#include <stdio.h>

int main()
{
    char A[100];
    int N, i;
    long long Ans = 1;
    scanf("%d", &N);
    char flag = 0;
    for(i = 0; i < N; ++i) {
        scanf("%hhd", &A[i]);
        flag |= A[i] == 1;
    }
    if(!flag) {
        puts("0");
        return 0;
    }
    int s = 0;
    while(s < N) {
        if(A[s] == 0) {
            int e = s;
            while(e + 1 < N && A[e + 1] == 0) {
                ++e;
            }
            if(s > 0 && A[s - 1] == 1 && e + 1 < N && A[e + 1] == 1) {
                Ans *= e - s + 1 + 1;
            }
            s = e;
        }
        ++s;
    }
    printf("%I64d\n", Ans);
    return 0;
}
