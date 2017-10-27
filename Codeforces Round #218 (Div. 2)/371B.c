#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int two, three, five;
} Node_t;
Node_t A, B;

void Init(Node_t *arg)
{
    while((*arg).num % 2 == 0) {
        (*arg).num /= 2;
        ++(*arg).two;
    }
    while((*arg).num % 3 == 0) {
        (*arg).num /= 3;
        ++(*arg).three;
    }
    while((*arg).num % 5 == 0) {
        (*arg).num /= 5;
        ++(*arg).five;
    }
}

int main()
{
    scanf("%d %d", &A.num, &B.num);
    if(A.num == B.num) {
        puts("0");
        return 0;
    }
    Init(&A);
    Init(&B);
    if(A.num != B.num) {
        puts("-1");
        return 0;
    }
    printf("%d\n", abs(A.two - B.two) + abs(A.three - B.three) + abs(A.five - B.five));
    return 0;
}
