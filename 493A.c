#include <stdio.h>

int A[2][100];

int main()
{
    int N, i;
    int t, m;
    char StrHome[21], StrAway[21];
    char Team[2], Card[2];
    scanf("%s %s", StrHome, StrAway);
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %s %d %s", &t, Team, &m, Card);
        if(Team[0] == 'h') {
            if(~A[0][m]) {
                if(Card[0] == 'r') {
                    printf("%s %d %d\n", StrHome, m , t);
                    A[0][m] = -1;
                } else {
                    if(A[0][m] == 0) {
                        A[0][m] = t;
                    } else {
                        printf("%s %d %d\n", StrHome, m , t);
                        A[0][m] = -1;
                    }
                }
            }
        } else {
            if(~A[1][m]) {
                if(Card[0] == 'r') {
                    printf("%s %d %d\n", StrAway, m , t);
                    A[1][m] = -1;
                } else {
                    if(A[1][m] == 0) {
                        A[1][m] = t;
                    } else {
                        printf("%s %d %d\n", StrAway, m , t);
                        A[1][m] = -1;
                    }
                }
            }
        }
    }
    return 0;
}
