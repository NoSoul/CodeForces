#include <stdio.h>

#define MAXN    100001

char Str[MAXN];
typedef struct {
    char ch;
    int cnt;
} Node_t;
Node_t Stack[MAXN];
int Size;

int main()
{
    int i;
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Size == 0) {
            Stack[Size].ch = Str[i];
            Stack[Size++].cnt = 1;
        } else {
            if(Str[i] != Stack[Size - 1].ch) {
                if(Size >= 2) {
                    if(Stack[Size - 1].cnt & 1) {
                        if(Stack[Size - 2].cnt & 1) {
                            Stack[Size].ch = Str[i];
                            Stack[Size++].cnt = 1;
                        } else {
                            if(Size == 2) {
                                Stack[Size - 2] = Stack[Size - 1];
                                --Size;
                            } else {
                                Stack[Size - 3].cnt += Stack[Size - 1].cnt;
                                Size -= 2;
                            }
                            Stack[Size].ch = Str[i];
                            Stack[Size++].cnt = 1;
                        }
                    } else {
                        --Size;
                        ++Stack[Size - 1].cnt;
                    }
                } else {
                    Stack[Size].ch = Str[i];
                    Stack[Size++].cnt = 1;
                }
            } else {
                ++Stack[Size - 1].cnt;
            }
        }
    }
    if(i & 1) {
        puts("No");
        return 0;
    }
    int flag = 1;
    for(i = 0; i < Size; ++i) {
        flag &= (Stack[i].cnt & 1) == 0;
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
