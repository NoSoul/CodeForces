#include <stdio.h>

int A[200000];

int main()
{
    int N, pre = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(pre) {
            if(A[i] == 0) {
                puts("NO");
                return 0;
            }
            --A[i];
        }
        A[i] &= 1;
        pre = A[i];
    }
    puts(pre ? "NO" : "YES");
    return 0;
}
