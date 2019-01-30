#include <stdio.h>

int main()
{
    char str[101];
    char minus = 0;
    scanf("%s", str);
    if(str[0] == '-') {
        minus = 1;
    }
    char integerStr[101];
    int integerLen = 0;
    for(int i = minus; str[i] != '.' && str[i]; ++i) {
        integerStr[integerLen++] = str[i];
    }
    int tail = 2;
    char fractionalStr[tail];
    int fractionalLen = 0;
    for(int i = 0; i < tail; ++i) {
        fractionalStr[i] = '0';
    }
    for(int i = minus + integerLen; str[i]; ++i) {
        if(str[i] >= '0' && str[i] <= '9') {
            fractionalStr[fractionalLen++] = str[i];
            if(fractionalLen == tail) {
                break;
            }
        }
    }
    if(minus) {
        putchar('(');
    }
    putchar('$');
    for(int i = 0; i < integerLen; ++i) {
        putchar(integerStr[i]);
        if(i != integerLen - 1 && (i + 1 - integerLen % 3) % 3 == 0) {
            putchar(',');
        }
    }
    putchar('.');
    for(int i = 0; i < tail; ++i) {
        putchar(fractionalStr[i]);
    }
    if(minus) {
        putchar(')');
    }
    return 0;
}
