#include <stdio.h>

long long A[200000];
long long Add[200000];

int main()
{
    int N, i, type, x, y;
    long long Sum = 0;
    int Size = 1;
    A[0] = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d %d", &x, &y);
            Add[x - 1] += y;
            Sum += x * y;
        } else if(type == 2) {
            scanf("%d", &x);
            A[Size++] = x;
            Sum += x;
        } else {
            Sum -= A[Size - 1] + Add[Size - 1];
            Add[Size - 2] += Add[Size - 1];
            Add[Size - 1] = 0;
            --Size;
        }
        printf("%.6f\n", 1.0 * Sum / Size);
    }
    return 0;
}
