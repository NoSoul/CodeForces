#include <stdio.h>

int GetSum(int id, int n)
{
    if(id == 0) {
        if(n == 1) {
            return 0;
        }
        return n;
    }
    if(id == n - 1 || id == n - 2) {
        return id;
    }
    if(id & 1) {
        return n + id;
    }
    return id;
}

int GetNum(int id, int n)
{
    if(id == 0) {
        return (n - 1) >> 1;
    }
    if(id >= 0 && !(id & 1) && id != n - 1) {
        return id >> 1;
    }
    int sum = GetSum(id, n);
    if(id == n - 1) {
        id = n;
    }
    if((id - 1) >> 1 & 1) {
        return ((n - 1) >> 1) + (id >> 1);
    }
    return sum - ((n - 1) >> 1) - (id >> 1);
}

int main()
{
    int N, i;
    scanf("%d", &N);
    if(!(N & 1)) {
        printf("-1\n");
        return 0;
    }
    for(i = 0; i < N; ++i) {
        printf("%d ", GetNum(i, N));
    }
    puts("");
    for(i = 0; i < N; ++i) {
        printf("%d ", GetSum(i, N) - GetNum(i, N));
    }
    puts("");
    for(i = 0; i < N; ++i) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}
