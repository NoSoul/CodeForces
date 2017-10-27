#include <stdio.h>

int main()
{
    char StrX[101], StrY[101];
    scanf("%s %s", StrX, StrY);
    for(int i = 0; StrY[i]; ++i) {
        if(StrX[i] < StrY[i]) {
            puts("-1");
            return 0;
        } else {
            StrX[i] = StrY[i];
        }
    }
    puts(StrX);
    return 0;
}
