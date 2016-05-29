#include <stdio.h>

char Flag[100000];
char Str[100001];
int Offset[100000];

int main()
{
    int N, i;
    char outFlag = 0;
    scanf("%d %s", &N, Str);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Offset[i]);
    }
    int s = 0;
    Flag[0] = 1;
    while(1) {
        int new;
        if(Str[s] == '>') {
            new = s + Offset[s];
        } else {
            new = s - Offset[s];
        }
        if(new < 0 || new >= N) {
            outFlag = 1;
            break;
        }
        if(Flag[new]) {
            break;
        }
        Flag[new] = 1;
        s = new;
    }
    puts(outFlag ? "FINITE" : "INFINITE");
    return 0;
}
