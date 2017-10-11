#include <stdio.h>

int main()
{
    int n, L;
    int A[50], B[50];
    scanf("%d %d", &n, &L);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if(i) {
            A[i] -= A[0];
        }
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
        if(i) {
            B[i] -= B[0];
        }
    }
    A[0] = B[0] = 0;
    char check = 1;
    for(int i = 0; i < n; ++i) {
        int dist = B[i] - A[0];
        check = 1;
        for(int j = i, k = 0; k < n; ++k) {
            int distprime;
            if(j < i) {
                distprime = L + B[j] - A[k];
            } else {
                distprime = B[j] - A[k];
            }
            if(distprime != dist) {
                check = 0;
                break;
            }
            if(++j == n) {
                j = 0;
            }
        }
        if(check) {
            break;
        }
    }
    puts(check ? "YES" : "NO");
    return 0;
}
