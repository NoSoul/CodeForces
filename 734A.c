#include <stdio.h>

int main()
{
    int cntA, cntD;
    char Str[100001];
    scanf("%*d %s", Str);
    cntA = cntD = 0;
    for(int i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'A') {
            ++cntA;
        } else {
            ++cntD;
        }
    }
    if(cntA > cntD) {
        puts("Anton");
    } else {
        puts(cntA == cntD ? "Friendship" : "Danik");
    }
    return 0;
}
