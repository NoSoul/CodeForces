#include <stdio.h>

char SName[101][11];
int S0[101], S1[101], S2[101], S3[101];
int T0, T1, T2, T3;

int main()
{
    int N, i;
    char Kind[11];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s %s", SName[i], Kind);
        if(Kind[0] == 'r') {
            S0[T0++] = i;
        } else if(Kind[0] == 'w' || (Kind[0] == 'c' && Kind[1] == 'h')) {
            S1[T1++] = i;
        } else if(Kind[0] == 'm') {
            S2[T2++] = i;
        } else {
            S3[T3++] = i;
        }
    }
    for(i = 0; i < T0; ++i) {
        printf("%s\n", SName[S0[i]]);
    }
    for(i = 0; i < T1; ++i) {
        printf("%s\n", SName[S1[i]]);
    }
    for(i = 0; i < T2; ++i) {
        printf("%s\n", SName[S2[i]]);
    }
    for(i = 0; i < T3; ++i) {
        printf("%s\n", SName[S3[i]]);
    }
    return 0;
}
