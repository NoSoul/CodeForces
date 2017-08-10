#include <stdio.h>

int main()
{
    int n, cnt = 0;
    int A[100];
    int Res[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    int last = -1;
    for(int i = 1; i < n; ++i) {
        if(A[i] > A[i - 1]) {
            if(last != 0) {
                Res[cnt++] = 0;
                last = 0;
            }
        } else if(A[i] == A[i - 1]) {
            if(last != 1) {
                Res[cnt++] = 1;
                last = 1;
            }
        } else {
            if(last != 2) {
                Res[cnt++] = 2;
                last = 2;
            }
        }
    }
    if(cnt > 3) {
        puts("NO");
    } else {
        for(int i = 1; i < cnt; ++i) {
            if(Res[i] <= Res[i - 1]) {
                puts("NO");
                return 0;
            }
        }
        puts("YES");
    }
    return 0;
}
