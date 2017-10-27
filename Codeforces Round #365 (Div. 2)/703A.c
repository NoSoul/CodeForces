#include <stdio.h>

int main()
{
    int N, m, c, A, B;
    scanf("%d", &N);
    A = 0;
    B = 0;
    while(N--) {
        scanf("%d %d", &m, &c);
        if(m > c) {
            ++A;
        } else if(m < c) {
            ++B;
        }
    }
    if(A == B) {
        puts("Friendship is magic!^^");
    } else {
        puts(A > B ? "Mishka" : "Chris");
    }
    return 0;
}
