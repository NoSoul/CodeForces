#include <stdio.h>

int main()
{
    int s;
    char Less20[20][20] = {"zero", "one", "two", "three", "four", "five" , "six", "seven", "eight", "nine",
                           "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
                          };
    char Ten[10][20] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    scanf("%d", &s);
    if(s < 20) {
        printf("%s", Less20[s]);
    } else {
        printf("%s", Ten[s / 10]);
        if(s % 10) {
            printf("-%s", Less20[s % 10]);
        }
    }
    puts("");
    return 0;
}
