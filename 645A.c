#include <stdio.h>
#include <string.h>

char Visit[256];

int Val(char *a)
{
    return (a[0] - 'A') * 64 + (a[1] - 'A') * 16 + (a[2] - 'A') * 4 + (a[3] - 'A');
}

void Change(char *str)
{
    if(str[0] == 'X') {
        str[0] = 'D';
    }
    if(str[1] == 'X') {
        str[1] = 'D';
    }
}

int main()
{
    char a[4];
    for(int i = 0; i < 2; ++i) {
        scanf("%s", a + 2 * i);
        Change(a + 2 * i);
    }
    int change[4][2] = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    Visit[Val(a)] = 1;
    char queue[256][4];
    int head = 0, tail = 1;
    for(int i = 0; i < 4; ++i) {
        queue[0][i] = a[i];
    }
    while(head < tail) {
        for(int i = 0; i < 4; ++i) {
            if(queue[head][i] == 'D') {
                char update[4];
                for(int j = 0; j < 2; ++j) {
                    for(int k = 0; k < 4; ++k) {
                        update[k] = queue[head][k];
                    }
                    char temp = update[change[i][j]];
                    update[change[i][j]] = update[i];
                    update[i] = temp;
                    if(!Visit[Val(update)]) {
                        Visit[Val(update)] = 1;
                        memcpy(queue[tail], update, sizeof(update));
                        ++tail;
                    }
                }
            }
        }
        ++head;
    }
    for(int i = 0; i < 2; ++i) {
        scanf("%s", a + 2 * i);
        Change(a + 2 * i);
    }
    puts(Visit[Val(a)] ? "YES" : "NO");
    return 0;
}
