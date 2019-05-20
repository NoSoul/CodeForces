#include <stdio.h>
#include <string.h>

int main()
{
    char t[100001];
    char stack[100001];
    int top = 0;
    scanf("%s", t);
    int len = strlen(t);
    for(int i = 0; i < len; ++i) {
        if(t[i] != 'a') {
            stack[top++] = t[i];
        }
        if(top == len - i - 1) {
            if(memcmp(stack, t + i + 1, top) == 0) {
                t[i + 1] = '\0';
                printf("%s", t);
                return 0;
            }
        }
    }
    puts(":(");
    return 0;
}
