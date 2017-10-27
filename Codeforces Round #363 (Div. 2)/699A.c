#include <stdio.h>

char Move[200001];
int Pos[200001];

int main()
{
    int N, Ans = -1;
    scanf("%d %s", &N, Move);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &Pos[i]);
        if(i > 0) {
            if(Move[i] == 'L' && Move[i - 1] == 'R') {
                int cur = (Pos[i] - Pos[i - 1]) / 2;
                if(Ans == -1) {
                    Ans = cur;
                } else {
                    if(Ans > cur) {
                        Ans = cur;
                    }
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
