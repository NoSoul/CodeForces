#include <stdio.h>
#include <string.h>

char Base[9] = "6789TJQKA";
char A[3], B[3];
char T;

int Judge()
{
    int i, j;
    for(i = 0; Base[i] != A[0]; ++i);
    for(j = 0; Base[j] != B[0]; ++j);
    if(A[1] == B[1] && i > j)
    {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%c %s %s", &T, A, B);
    if((A[1] == T && B[1] != T) || Judge())
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}
