#include <stdio.h>

int main()
{
    int N, i, Pre, Ans;
    char A[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%hhd", &A[i]);
    }
    Pre = -1;
    Ans = 0;
    for(i = 0; i < N; ++i) {
        if(A[i]) {
            if(~Pre) {
                if(i - Pre == 2) {
                    ++Ans;
                }
            }
            ++Ans;
            Pre = i;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
