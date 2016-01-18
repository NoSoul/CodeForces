#include <stdio.h>

int LeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int FirstDayOfWeek(int year)
{
    if(year == 1583) {
        return 4;
    }
    return (FirstDayOfWeek(year - 1) + LeapYear(year - 1) + 365 - 1) % 7;
}

int main()
{
    int i, x, remain = 1, Ans = 0;
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek[7] = {52, 52, 52, 52, 52, 52, 52};
    if(LeapYear(2016)) {
        dayOfMonth[1] = 29;
        ++remain;
    }
    int s = FirstDayOfWeek(2016);
    for(i = 0; i < remain; ++i) {
        ++dayOfWeek[s];
        s = (s + 1) % 7;
    }
    char Str[6];
    scanf("%d %*s %s", &x, Str);
    if(Str[0] == 'm') {
        for(i = 0; i < 12; ++i) {
            if(dayOfMonth[i] >= x) {
                ++Ans;
            }
        }
    } else {
        Ans = dayOfWeek[x - 1];
    }
    printf("%d\n", Ans);
    return 0;
}
