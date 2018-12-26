#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point_t;
Point_t His[3];
int Size;

int main()
{
    int n, m;
    char str[101];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < m; ++j) {
            if(str[j] == '*') {
                His[Size].x = i;
                His[Size].y = j;
                ++Size;
            }
        }
    }
    for(int i = 0; i < 3; ++i) {
        int j;
        for(j = 0; j < 3; ++j) {
            if(i != j && His[i].x == His[j].x) {
                break;
            }
        }
        if(j == 3) {
            int ansX = His[i].x;
            for(j = 0; j < 3; ++j) {
                if(His[j].y != His[i].y) {
                    printf("%d %d\n", His[i].x + 1, His[j].y + 1);
                }
            }
        }
    }
    return 0;
}
