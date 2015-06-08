#include <stdio.h>
#include <string.h>

#define MAX 51

int P[MAX], Top;
char B[MAX];

void Init()
{
    int i, j;
    B[0] = B[1] = 1;
    for(i = 2; i < MAX; ++i) {
        if(!B[i]) {
            P[Top++] = i;
            for(j = i << 1; j < MAX; j += i) {
                B[j] = 1;
            }
        }
    }
}

int main()
{
    int N, M, i;
    Init();
    scanf("%d %d", &N, &M);
    for(i = 0; i < Top; ++i) {
        if(P[i] == N) {
            break;
        }
    }
    puts(M == P[i + 1] ? "YES" : "NO");
    return 0;
}
