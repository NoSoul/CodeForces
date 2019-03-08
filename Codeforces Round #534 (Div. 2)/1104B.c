#include <stdio.h>

int main()
{
    char str[100001];
    char stack[100001];
    int size = 0, cnt = 0;
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
        if(size && str[i] == stack[size - 1]) {
            --size;
            ++cnt;
        } else {
            stack[size++] = str[i];
        }
    }
    puts(cnt & 1 ? "Yes" : "No");
    return 0;
}
