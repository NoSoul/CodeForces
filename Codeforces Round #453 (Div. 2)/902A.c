#include <stdio.h>

int Flag[101];
char Visit[101];
int Queue[101];

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if(b > Flag[a]) {
            Flag[a] = b;
        }
    }
    int s = 0, head = 0, tail = 1;
    Visit[s] = 1;
    Queue[0] = s;
    while(head < tail) {
        for(int i = Queue[head]; i <= Flag[Queue[head]]; ++i) {
            if(i == m) {
                puts("YES");
                return 0;
            }
            if(Flag[i] && !Visit[i]) {
                Queue[tail++] = i;
                Visit[i] = 1;
            }
        }
        ++head;
    }
    puts(Visit[m] ? "YES" : "NO");
    return 0;
}
