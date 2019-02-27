#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point_t;

int main()
{
    char pos[3];
    Point_t A[2];
    int step[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    for(int i = 0; i < 2; ++i) {
        scanf("%s", pos);
        A[i].x = pos[0] - 'a';
        A[i].y = pos[1] - '1';
    }
    int ans = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(i == A[0].x || j == A[0].y) {
                continue;
            }
            if(i == A[1].x && j == A[1].y) {
                continue;
            }
            int k;
            for(k = 0; k < 8; ++k) {
                int x = i + step[k][0];
                int y = j + step[k][1];
                if(x >= 0 && x < 8 && y >= 0 && y < 8) {
                    if((x == A[0].x && y == A[0].y) || (x == A[1].x && y == A[1].y)) {
                        break;
                    }
                }
            }
            if(k == 8) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
