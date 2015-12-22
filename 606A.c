#include <stdio.h>

int main()
{
    int i, j, k;
    int A[3], B[3];
    for(i = 0; i < 3; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < 3; ++i) {
        scanf("%d", &B[i]);
    }
    while(1) {
        j = -1;
        for(i = 0; i < 3; ++i) {
            if(A[i] - B[i] >= 2) {
                j = i;
                break;
            }
        }
        if(j == -1) {
            break;
        }
        k = -1;
        for(i = 0; i < 3; ++i) {
            if(A[i] < B[i]) {
                k = i;
                break;
            }
        }
        if(k == -1) {
            break;
        }
        A[j] -= 2;
        ++A[k];
        for(i = 0; i < 3; ++i) {
            if(A[i] < B[i]) {
                break;
            }
        }
        if(i == 3) {
            break;
        }
    }
    for(i = 0; i < 3; ++i) {
        if(A[i] < B[i]) {
            break;
        }
    }
    puts(i == 3 ? "Yes" : "No");
    return 0;
}
