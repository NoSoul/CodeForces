#include <stdio.h>

int A[100001];

int main()
{
    int N, M, Add, i, t, x, y;
    Add = 0;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    while(M--) {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d %d", &x, &y);
            A[x] = y - Add;
        } else if(t == 2) {
            scanf("%d", &x);
            Add += x;
        } else {
            scanf("%d", &x);
            printf("%d\n", A[x] + Add);
        }
    }
    return 0;
}
