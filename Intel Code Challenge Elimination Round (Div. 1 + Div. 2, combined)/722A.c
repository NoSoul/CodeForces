#include <stdio.h>


int main()
{
    int format, num;
    char Str[6];
    scanf("%d %s", &format, Str);
    num = (Str[0] - '0') * 10 + Str[1] - '0';
    if(format == 12) {
        if(num == 0) {
            Str[1] = '1';
        } else if(num > 12) {
            if(num % 10 == 0) {
                Str[0] = '1';
            } else {
                Str[0] = '0';
            }
        }
    } else {
        if(num > 23) {
            if(num % 10 == 0) {
                Str[0] = '1';
            } else {
                Str[0] = '0';
            }
        }
    }
    num = (Str[3] - '0') * 10 + Str[4] - '0';
    if(num > 59) {
        Str[3] = '0';
    }
    puts(Str);
    return 0;
}
