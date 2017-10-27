#include <stdio.h>

char GetNEQ(char a, char b)
{
    int i;
    for(i = 'a'; i <= 'z'; ++i) {
        if(i != a && i != b) {
            return i;
        }
    }
    return 'a';
}

int main()
{
    int n, t, m, i;
    char Str1[100001];
    char Str2[100001];
    char Str3[100001];
    scanf("%d %d %s %s", &n, &t, Str1, Str2);
    for(i = m = 0; Str1[i]; ++i) {
        if(Str1[i] != Str2[i]) {
            ++m;
        }
    }
    if(m - m / 2 > t) {
        puts("-1");
        return 0;
    }
    if(m <= t) {
        m = t - m;
        for(i = 0; Str1[i]; ++i) {
            if(Str1[i] == Str2[i]) {
                if(m) {
                    --m;
                    Str3[i] = GetNEQ(Str1[i], Str2[i]);
                } else {
                    Str3[i] = Str1[i];
                }
            } else {
                Str3[i] = GetNEQ(Str1[i], Str2[i]);
            }
        }
    } else {
        m = m - t;
        m *= 2;
        for(i = 0; Str1[i]; ++i) {
            if(Str1[i] == Str2[i]) {
                Str3[i] = Str1[i];
            } else {
                if(m) {
                    Str3[i] = m & 1 ? Str1[i] : Str2[i];
                    --m;
                } else {
                    Str3[i] = GetNEQ(Str1[i], Str2[i]);
                }
            }
        }
    }
    Str3[n] = '\0';
    puts(Str3);
    return 0;
}
