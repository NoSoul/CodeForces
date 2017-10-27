#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 1000; ++j) {
            int remain = N - i * 1234567 - j * 123456;
            if(remain >= 0 && remain % 1234 == 0) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
