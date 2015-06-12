#include <stdio.h>

int main()
{
    int N, A, B, i, Num;
    scanf("%d %d %d", &N, &A, &B);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        if(A >= B) {
            printf("0 ");
        } else {
            long long cur = (long long)Num * A / B;
            Num -= cur * B / A;
            if((cur * B) % A) {
                --Num;
            }
            printf("%d ", Num);
        }
    }
    puts("");
    return 0;
}
