#include <stdio.h>
#include <string.h>

#define MAXN 100001

char Str[MAXN];
int Ans[MAXN];
int Size;
int A[2];

int main()
{
    int i, Len, Remain;
    scanf("%s", Str);
    Len = strlen(Str);
    Remain = 0;
    for(i = 0; i < Len; ++i) {
        if(Str[i] == '#') {
            ++Size;
            ++A[0];
        } else if(Str[i] == '(') {
            ++A[1];
            ++Remain;
        } else {
            ++A[0];
            --Remain;
        }
    }
    if(Remain < Size) {
        puts("-1");
        return 0;
    }
    for(i = 0; i < Size; ++i) {
        Ans[i] = 1;
    }
    Remain -= Size;
    int Idx = Size - 1;
    for(i = Len - 1; i >= 0; --i) {
        if(Str[i] == '(') {
            --A[1];
        } else if(Str[i] == ')') {
            --A[0];
        } else {
            int bound = A[1] - A[0];
            if(bound < 0) {
                puts("-1");
                return 0;
            }
            if(Remain > bound) {
                Ans[Idx] += bound;
                Remain -= bound;
                A[0] -= Ans[Idx];
            } else {
                Ans[Idx] += Remain;
                Remain = 0;
                break;
            }
            --Idx;
        }
    }
    int check = 0;
    Idx = 0;
    for(i = 0; i < Len; ++i) {
        if(Str[i] == '(') {
            ++check;
        } else if(Str[i] == ')') {
            --check;
        } else {
            check -= Ans[Idx++];
        }
        if(check < 0) {
            puts("-1");
            return 0;
        }
    }
    if(check != 0) {
        puts("-1");
        return 0;
    }
    for(i = 0 ; i < Size; ++i) {
        printf("%d\n", Ans[i]);
    }
    return 0;
}
