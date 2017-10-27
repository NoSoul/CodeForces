#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Str1[31], Str2[31];


int main()
{
    int A, C, L1, L2, L, i, p = 1, ans;
    scanf("%d %d", &A, &C);
    itoa(A, Str1, 3);
    itoa(C, Str2, 3);
    L1 = strlen(Str1);
    L2 = strlen(Str2);
    L = L1 > L2 ? L1 : L2;
    strrev(Str1);
    strrev(Str2);
    if(L1 > L2) {
        for(i = L2; i < L; ++i) {
            Str2[i] = '0';
        }
    } else {
        for(i = L1; i < L; ++i) {
            Str1[i] = '0';
        }
    }
    for(p = 1, ans = i = 0; i < L; ++i) {
        ans += ((Str2[i] + 3 - Str1[i]) % 3) * p;
        p *= 3;
    }
    printf("%d\n", ans);
    return 0;
}
