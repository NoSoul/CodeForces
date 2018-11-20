#include <stdio.h>

typedef struct {
    int x, y;
} Point;

int main()
{
    Point A, B, C;
    scanf("%d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
    B.x -= A.x;
    B.y -= A.y;
    C.x -= A.x;
    C.y -= A.y;
    if(B.x * C.y == C.x * B.y) {
        puts("TOWARDS");
        return 0;
    }
    B.x += A.x;
    B.y += A.y;
    C.x += A.x;
    C.y += A.y;
    if(A.x == B.x && A.y < B.y) {
        if(C.x < B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.x == B.x && A.y > B.y) {
        if(C.x > B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.y == B.y && A.x > B.x) {
        if(C.y < B.y) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }

    }
    if(A.y == B.y && A.x < B.x) {
        if(C.y > B.y) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.x > B.x && A.y < B.y) {
        if(C.x < B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.x < B.x && A.y < B.y) {
        if(C.x < B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.x < B.x && A.y > B.y) {
        if(C.x > B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    if(A.x > B.x && A.y > B.y) {
        if(C.x > B.x) {
            puts("LEFT");
        } else {
            puts("RIGHT");
        }
    }
    return 0;
}
