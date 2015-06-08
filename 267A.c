#include <stdio.h>

int Fun(int a, int b)
{
    int cnt = 0;
    while(a > 0 && b > 0) {
        if(a == b) {
            ++cnt;
            break;
        } else if(a > b) {
            cnt += a / b;
            a -= (a / b) * b;
        } else {
            cnt += b / a;
            b -= (b / a) * a;
        }
    }
    return cnt;
}

int main()
{
    int N, A, B;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", Fun(A, B));
    }
    return 0;
}

