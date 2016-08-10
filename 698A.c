#include <stdio.h>

int A[101];

int main()
{
    int N, Ans;
    scanf("%d", &N);
    Ans = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    int flag = 0;
    for(int i = 0; i < N; ++i) {
        if(A[i] == 0) {
            ++Ans;
            flag = 0;
        } else if(A[i] == 1) {
            if(flag == 1) {
                ++Ans;
                flag = 0;
            } else {
                flag = 1;
            }
        } else if(A[i] == 2) {
            if(flag == 2) {
                ++Ans;
                flag = 0;
            } else {
                flag = 2;
            }
        } else {
            if(flag == 1) {
                flag = 2;
            } else if(flag == 2) {
                flag = 1;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
