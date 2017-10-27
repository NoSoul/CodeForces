#include <stdio.h>

typedef struct {
    int x, y;
} Point_t;

int main()
{
    Point_t A[3], Ans[3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d %d", &A[i].x, &A[i].y);
    }
    for(int i = 0; i < 3; ++i) {
        Ans[i].x = Ans[i].y = 0;
        for(int j = 0; j < 3; ++j) {
            if(i != j) {
                Ans[i].x += A[j].x;
                Ans[i].y += A[j].y;
            } else {
                Ans[i].x -= A[j].x;
                Ans[i].y -= A[j].y;
            }
        }
    }
    printf("%d\n", 3);
    for(int i = 0; i < 3; ++i) {
        printf("%d %d\n", Ans[i].x, Ans[i].y);
    }
    return 0;
}
