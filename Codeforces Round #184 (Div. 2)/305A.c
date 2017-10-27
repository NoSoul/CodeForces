#include <stdio.h>

char Hash[101];

int main()
{
    int N, i, Num, Cnt, zero = 0, two = 0, one = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        Hash[Num] = 1;
        if(Num == 0) {
            ++zero;
        }
    }
    Cnt = zero;
    if(Hash[100]) {
        ++Cnt;
    }
    for(i = 90; i > 0; i -= 10) {
        if(Hash[i]) {
            two = i;
            break;
        }
    }
    for(i = 9; i > 0; --i) {
        if(Hash[i]) {
            two += i;
            break;
        }
    }
    for(i = 99; i > 0; --i) {
        if(Hash[i]) {
            one = i;
            break;
        }
    }
    if(two % 10 != 0 && two / 10 != 0) {
        Cnt += 2;
    } else if(one != 0) {
        ++Cnt;
    }
    printf("%d\n", Cnt);
    if(Hash[100]) {
        printf("100 ");
        Cnt -= 1;
    }
    if(Cnt != zero) {
        if(two % 10 != 0 && two / 10 != 0) {
            printf("%d %d ", two % 10, (two / 10) * 10);
        } else if(one != 0) {
            printf("%d ", one);
        }
    }
    for(i = 0; i < zero; ++i) {
        printf("0 ");
    }
    return 0;
}
