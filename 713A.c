#include <stdio.h>
#include <string.h>

#define MAXLEN  19

typedef struct {
    int next[2];
    int cnt;
} Node_t;
Node_t Tree[100000 * MAXLEN];
int Size;

int main()
{
    int t, num;
    char Str[2], pattern[MAXLEN], format[MAXLEN];
    scanf("%d", &t);
    Tree[Size].next[0] = -1;
    Tree[Size].next[1] = -1;
    Tree[Size].cnt = 0;
    ++Size;
    while(t--) {
        scanf("%s %s", Str, pattern);
        int pLen = strlen(pattern);
        for(int i = 0; i < MAXLEN; ++i) {
            int idx = pLen - 1 - i;
            if(idx >= 0) {
                num = (pattern[idx] - '0') & 1;
            } else {
                num = 0;
            }
            format[MAXLEN - 1 - i] = num;
        }
        int j = 0;
        for(int i = 0; i < MAXLEN; ++i) {
            if(Tree[j].next[format[i]] == -1) {
                Tree[j].next[format[i]] = Size;
                Tree[Size].next[0] = -1;
                Tree[Size].next[1] = -1;
                Tree[Size].cnt = 0;
                ++Size;
            }
            j = Tree[j].next[format[i]];
            if(i == MAXLEN - 1) {
                if(Str[0] == '+') {
                    ++Tree[j].cnt;
                } else if(Str[0] == '-') {
                    --Tree[j].cnt;
                } else {
                    printf("%d\n", Tree[j].cnt);
                }
            }
        }
    }
    return 0;
}
