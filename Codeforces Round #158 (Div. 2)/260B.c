#include <stdio.h>

char Str[100001];
int Hash[365 * 3 + 1];
int Date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Judge(int i)
{
    int d, m, y;
    if(Str[i] != '-' && Str[i + 1] != '-' && Str[i + 2] == '-' && Str[i + 3] != '-' && Str[i + 4] != '-' && Str[i + 5] == '-' && Str[i + 6] != '-' && Str[i + 7] != '-' && Str[i + 8] != '-' && Str[i + 9] != '-') {
        d = (Str[i] - '0') * 10 + Str[i + 1] - '0';
        m = (Str[i + 3] - '0') * 10 + Str[i + 4] - '0';
        y = (Str[i + 6] - '0') * 1000 + (Str[i + 7] - '0') * 100 + (Str[i + 8] - '0') * 10 + Str[i + 9] - '0';
        if(m > 0 && m < 13 && d > 0 && d <= Date[m] && y > 2012 && y < 2016) {
            for(i = 1; i < m; ++i) {
                d += Date[i];
            }
            ++Hash[(y - 2013) * 365 + d];
        }
    }
    return;
}

int main()
{
    int i, Max, Maxi, y;
    scanf("%s", Str);
    for(i = 0; Str[i + 9] != '\0'; ++i) {
        Judge(i);
    }
    for(Max = 0, i = 365 * 3; i > 0; --i) {
        if(Hash[i] > Max) {
            Max = Hash[i];
            Maxi = i;
        }
    }
    if(Maxi % 365 == 0) {
        printf("31-12-%d\n", 2012 + Maxi / 365);
        return 0;
    }
    y = Maxi / 365 + 2013;
    Maxi %= 365;
    for(i = 1; i < 13; ++i) {
        if(Maxi <= Date[i]) {
            break;
        }
        Maxi -= Date[i];
    }
    printf("%02d-%02d-%d\n", Maxi, i, y);
    return 0;
}
