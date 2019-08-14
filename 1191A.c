#include <stdio.h>
#include <string.h>

int main()
{
    int x;
    int val[4];
    scanf("%d", &x);
    memset(val, -1, sizeof(val));
    for(int a = 0; a < 3; ++a) {
        val[(a + x) & 3] = a;
    }
    int table[] = {1, 3, 2, 0};
    for(int i = 0; i < 4; ++i) {
        if(~val[table[i]]) {
            printf("%d %c\n", val[table[i]], 'A' + i);
            break;
        }
    }
    return 0;
}
