#include <stdio.h>

int A[1000001];

int main()
{
    int n, i, max = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &i);
        if(++A[i] > A[max]) {
            max = i;
        }
    }
    printf("%d\n", max);
    return 0;
}
