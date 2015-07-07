#include <stdio.h>

int main()
{
    int N, l, r, Ql, Qr, i, j, Sum;
    int W[100001];
    int Add[100001];
    scanf("%d %d %d %d %d", &N, &l, &r, &Ql, &Qr);
    Add[0] = 0;
    for(i = 1; i <= N; ++i) {
        scanf("%d", &W[i]);
        Add[i] = W[i] + Add[i - 1];
    }
    int Min = 0x7f7f7f7f;
    i = 1, j = N, Sum = 0;
    while(i <= j) {
        Sum += W[i] * l;
        ++i;
        if(Sum + (j - i + 1)*Ql + (Add[j] - Add[i - 1])*l < Min) {
            Min = Sum + (j - i + 1) * Ql + (Add[j] - Add[i - 1]) * l;
        }
        if(i > j) {
            break;
        }
        Sum += W[j] * r;
        --j;
        if(Sum + (j - i + 1)*Qr + (Add[j] - Add[i - 1])*r < Min) {
            Min = Sum + (j - i + 1) * Qr + (Add[j] - Add[i - 1]) * r;
        }
    }
    if(Sum < Min) {
        Min = Sum;
    }
    i = 1, j = N, Sum = 0;
    while(i <= j) {
        Sum += W[j] * r;
        --j;
        if(Sum + (j - i + 1)*Qr + (Add[j] - Add[i - 1])*r < Min) {
            Min = Sum + (j - i + 1) * Qr + (Add[j] - Add[i - 1]) * r;
        }
        if(i > j) {
            break;
        }
        Sum += W[i] * l;
        ++i;
        if(Sum + (j - i + 1)*Ql + (Add[j] - Add[i - 1])*l < Min) {
            Min = Sum + (j - i + 1) * Ql + (Add[j] - Add[i - 1]) * l;
        }
    }
    if(Sum < Min) {
        Min = Sum;
    }
    printf("%d\n", Min);
    return 0;
}
