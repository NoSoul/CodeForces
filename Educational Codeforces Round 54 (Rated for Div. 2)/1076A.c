#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[200001];
    scanf("%d %s", &n, s);
    int find = strlen(s) - 1;
    for(int i = 0; s[i + 1]; ++i) {
        if(s[i] > s[i + 1]) {
            find = i;
            break;
        }
    }
    for(int i = 0; s[i]; ++i) {
        if(i != find) {
            putchar(s[i]);
        }
    }
    putchar('\n');
    return 0;
}
