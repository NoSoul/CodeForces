#include <stdio.h>

typedef struct {
    int m_year;
    int m_month;
    int m_day;
} Date_t;

int Month[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Leap(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}

int main()
{
    int i, Sum;
    Date_t start, end, temp;
    scanf("%d:%d:%d %d:%d:%d", &start.m_year, &start.m_month, &start.m_day, &end.m_year, &end.m_month, &end.m_day);
    if(start.m_year > end.m_year || (start.m_year == end.m_year && start.m_month > end.m_month) || (start.m_year == end.m_year && start.m_month == end.m_month && start.m_day > end.m_day)) {
        temp = start;
        start = end;
        end = temp;
    }
    if(start.m_year == end.m_year) {
        if(start.m_month == end.m_month) {
            printf("%d\n", end.m_day - start.m_day);
        } else {
            if(Leap(start.m_year)) {
                Month[2] = 29;
            }
            Sum = Month[start.m_month] - start.m_day;
            for(i = start.m_month + 1; i < end.m_month; ++i) {
                Sum += Month[i];
            }
            Sum += end.m_day;
            printf("%d\n", Sum);
        }
        return 0;
    }
    for(Sum = 0, i = start.m_year + 1; i < end.m_year; ++i) {
        Sum += Leap(i) ? 366 : 365;
    }
    if(Leap(start.m_year)) {
        Month[2] = 29;
    }
    Sum += Month[start.m_month] - start.m_day;
    for(i = start.m_month + 1; i < 13; ++i) {
        Sum += Month[i];
    }
    Month[2] = 28;
    if(Leap(end.m_year)) {
        Month[2] = 29;
    }
    Sum += end.m_day;
    for(i = 1; i < end.m_month; ++i) {
        Sum += Month[i];
    }
    printf("%d\n", Sum);
    return 0;
}
