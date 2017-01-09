#include <stdio.h>

int main()
{
    int N, Cnt = 0;
    int A[100];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        Cnt += A[i] != 0;
    }
    if(Cnt == 0) {
        puts("NO");
    } else {
        puts("YES");
        printf("%d\n", Cnt);
        int l;
        l = 1;
        while(Cnt--) {
            for(int i = l - 1; i < N; ++i) {
                if(A[i] != 0) {
                    if(Cnt == 0) {
                        printf("%d %d\n", l, N);
                    } else {
                        printf("%d %d\n", l, i + 1);
                    }
                    l = i + 2;
                    break;
                }
            }
        }
    }
    return 0;
}
