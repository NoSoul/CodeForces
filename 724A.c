#include <stdio.h>
#include <string.h>

char Day[7][16] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

void Set(int *ans)
{
    char Str[16];
    scanf("%s", Str);
    for(int i = 0; i < 7; ++i) {
        if(strcmp(Day[i], Str) == 0) {
            *ans = i;
            return;
        }
    }
}

int main()
{
    int A, B;
    int data[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Set(&A);
    Set(&B);
    for(int i = 0; i < 7; ++i) {
        int cur = i;
        for(int j = 0; j < 12; ++j) {
            int next = (cur + data[j]) % 7;
            if(cur == A && next == B) {
                puts("YES");
                return 0;
            }
            cur = next;
        }
    }
    puts("NO");
    return 0;
}
