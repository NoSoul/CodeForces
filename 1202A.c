#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    char strX[100001];
    char strY[100001];
    scanf("%d", &T);
    while(T--) {
        scanf("%s %s", strX, strY);
        int lenX = strlen(strX);
        int lenY = strlen(strY);
        int idxY = -1;
        for(int i = lenY - 1; i >= 0; --i) {
            if(strY[i] == '1') {
                idxY = i;
                break;
            }
        }
        if(idxY == -1) {
            puts("0");
        } else {
            char find = 0;
            int ans = 0;
            for(int i = lenX - 1 - (lenY - 1 - idxY); i >= 0; --i) {
                if(strX[i] == '1') {
                    find = 1;
                    break;
                }
                ++ans;
            }
            printf("%d\n", find ? ans : 0);
        }
    }
    return 0;
}
