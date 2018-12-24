#include <stdio.h>

int main()
{
    int h1, a1, c1, h2, a2;
    scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
    int curH = h1;
    int Ans[20000];
    int Cnt = 0;
    while(1) {
        if(curH > a2 || a1 >= h2) {
            h2 -= a1;
            Ans[Cnt++] = 0;
        } else {
            curH += c1;
            if(curH > h1) {
                h1 = curH;
            }
            Ans[Cnt++] = 1;
        }
        curH -= a2;
        if(h2 <= 0) {
            break;
        }
    }
    printf("%d\n", Cnt);
    for(int i = 0; i < Cnt; ++i) {
        puts(Ans[i] ? "HEAL" : "STRIKE");
    }
    return 0;
}
