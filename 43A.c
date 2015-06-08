#include <stdio.h>
#include <string.h>

char T1[11], T2[11];
int  C1, C2;

int main()
{
    int N, flag = 0;
    char S[11];
    scanf("%d %s", &N, T1);
    ++C1;
    while(--N) {
        scanf("%s", S);
        if(strcmp(S, T1) == 0) {
            ++C1;
        } else {
            ++C2;
            if(!flag) {
                flag = 1;
                strcpy(T2, S);
            }
        }
    }
    puts(C1 > C2 ? T1 : T2);
    return 0;
}
