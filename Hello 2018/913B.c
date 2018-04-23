#include <stdio.h>

int Flag[1001];
char NotLeaf[1001];
int P[1001];

int main()
{
    int n;
    scanf("%d", &n);
    NotLeaf[1] = 1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &P[i]);
        NotLeaf[P[i]] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(!NotLeaf[i + 1]) {
            ++Flag[P[i]];
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(NotLeaf[i] && Flag[i] < 3) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
