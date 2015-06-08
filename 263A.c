#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, indi, indj, num;
    for(i = 0; i < 5; ++i) {
        for(j = 0; j < 5; ++j) {
            scanf("%d", &num);
            if(num) {
                indi = i;
                indj = j;
            }
        }
    }
    printf("%d\n", abs(indi - 2) + abs(indj - 2));
    return 0;
}

