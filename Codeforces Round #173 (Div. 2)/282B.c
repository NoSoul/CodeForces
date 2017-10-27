#include <stdio.h>

int main()
{
    int N, a, g, Suma, Sumg, Cnt;
    char Str[1000001];
    scanf("%d", &N);
    Cnt = Suma = Sumg = 0;
    while(N--) {
        scanf("%d %d", &a, &g);
        if(abs(Suma + a - Sumg) <= 500) {
            Suma += a;
            Str[Cnt++] = 'A';
        } else {
            Sumg += g;
            Str[Cnt++] = 'G';
        }
    }
    Str[Cnt] = '\0';
    puts(abs(Suma - Sumg) <= 500 ? Str : "-1");
    return 0;
}
