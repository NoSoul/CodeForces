#include <stdio.h>

int main()
{
    int N, M;
    char ch[2], flag = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N * M; ++i) {
        scanf("%s", ch);
        if(ch[0] == 'C' || ch[0] == 'M' || ch[0] == 'Y') {
            flag = 1;
        }
    }
    puts(flag ? "#Color" : "#Black&White");
    return 0;
}
