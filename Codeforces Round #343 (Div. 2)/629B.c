#include <stdio.h>

int F[367];
int M[367];

int main()
{
    int N, i, j, a, b, Max = 0;
    char sex[2];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s %d %d", sex, &a, &b);
        if(sex[0] == 'F') {
            for(j = a; j <= b; ++j) {
                ++F[j];
            }
        }
        if(sex[0] == 'M') {
            for(j = a; j <= b; ++j) {
                ++M[j];
            }
        }
    }
    for(i = 1; i < 367; ++i) {
        int cur = F[i] < M[i] ? F[i] : M[i];
        if(cur > Max) {
            Max = cur;
        }
    }
    printf("%d\n", Max << 1);
    return 0;
}
