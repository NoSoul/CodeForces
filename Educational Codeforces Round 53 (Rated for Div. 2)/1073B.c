#include <stdio.h>

int Pos[200001];

int main()
{
    int n, a, b;
    int top = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        Pos[a] = i + 1;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b);
        if(top < Pos[b]) {
            printf("%d ", Pos[b] - top);
            top = Pos[b];
        } else {
            printf("0 ");
        }
    }
    puts("");
    return 0;
}
