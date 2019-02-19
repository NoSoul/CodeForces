#include <stdio.h>

#define MAX 101

int main()
{
    int i, A, B;
    char Str[MAX];
    scanf("%s", Str);
    for(A = B = i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] < 'a') {
            ++A;
        } else {
            ++B;
        }
    }
    if(A <= B) {
        for(i = 0; Str[i] != '\0'; ++i) {
            if(Str[i] < 'a') {
                Str[i] += 32;
            }
        }
    } else {
        for(i = 0; Str[i] != '\0'; ++i) {
            if(Str[i] > 'Z') {
                Str[i] -= 32;
            }
        }
    }
    puts(Str);
    return 0;
}
