#include <stdio.h>

int GetSum(int n)
{
    return (1 + 1 + (n - 1) * 2) * n / 2;
}

int main()
{
    int a1, a2, a3, a4, a5, a6;
    int Ans = 0;
    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
    if(a2 == a6) {
        Ans += GetSum(a1 + a2) - GetSum(a1);
        Ans += GetSum(a4 + a3) - GetSum(a4);
    } else if(a2 < a6) {
        Ans += GetSum(a1 + a2) - GetSum(a1);
        Ans += (a6 - a2) * (a4 + a5) * 2;
        Ans += GetSum(a4 + a5) - GetSum(a4);
    } else {
        Ans += GetSum(a1 + a6) - GetSum(a1);
        Ans += (a2 - a6) * (a4 + a3) * 2;
        Ans += GetSum(a4 + a3) - GetSum(a4);
    }
    printf("%d\n", Ans);
    return 0;
}
