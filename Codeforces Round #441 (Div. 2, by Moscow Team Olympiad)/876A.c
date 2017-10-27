#include <stdio.h>

int main()
{
    int n, a, b, c, s, Ans = 0;
    int Map[3][3];
    scanf("%d %d %d %d", &n, &a, &b, &c);
    Map[0][1] = Map[1][0] = a;
    Map[0][2] = Map[2][0] = b;
    Map[1][2] = Map[2][1] = c;
    for(int i = 0; i < 3; ++i) {
        Map[i][i] = 0x7f7f7f7f;
    }
    s = 0;
    while(--n) {
        int find = s;
        for(int i = 0; i < 3; ++i) {
            if(Map[s][i] < Map[s][find]) {
                find = i;
            }
        }
        Ans += Map[s][find];
        s = find;
    }
    printf("%d\n", Ans);
    return 0;
}
