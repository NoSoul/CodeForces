#include <stdio.h>
#include <string.h>

#define MAXN    100001

typedef struct {
    int num[26];
} Node_t;

void Set(Node_t *a, char *str)
{
    int i;
    memset(a->num, 0, sizeof(a->num));
    for(i = 0; str[i]; ++i) {
        ++a->num[str[i] - 'a'];
    }
}

int Num(Node_t *a, Node_t *b)
{
    int i, ret = 0x7fffffff;
    for(i = 0; i < 26; ++i) {
        if(b->num[i]) {
            if(a->num[i] / b->num[i] < ret) {
                ret = a->num[i] / b->num[i];
            }
        }
    }
    return ret;
}

void Sub(Node_t *a, Node_t *b)
{
    int i;
    for(i = 0; i < 26; ++i) {
        a->num[i] -= b->num[i];
    }
}

void Remain(Node_t *a)
{
    int i;
    for(i = 0; i < 26; ++i) {
        while(a->num[i]--) {
            putchar('a' + i);
        }
    }
    putchar('\n');
}

int main()
{
    Node_t A, B, C;
    char StrA[MAXN], StrB[MAXN], StrC[MAXN];
    scanf("%s %s %s", StrA, StrB, StrC);
    Set(&A, StrA);
    Set(&B, StrB);
    Set(&C, StrC);
    while(Num(&A, &B) && Num(&A, &C)) {
        if(Num(&A, &B) > Num(&A, &C)) {
            Sub(&A, &B);
            printf("%s", StrB);
        } else {
            Sub(&A, &C);
            printf("%s", StrC);
        }
    }
    while(Num(&A, &B)) {
        Sub(&A, &B);
        printf("%s", StrB);
    }
    while(Num(&A, &C)) {
        Sub(&A, &C);
        printf("%s", StrC);
    }
    Remain(&A);
    return 0;
}
