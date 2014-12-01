#include <stdio.h>
#include <string.h>

int Hash[26];

int main()
{
    int i, Len;
    char List[] = {"AHIMOTUVWXY"};
    char Str[100001];
    Hash['A' - 'A'] = 1;
    Hash['H' - 'A'] = 1;
    Hash['I' - 'A'] = 1;
    Hash['M' - 'A'] = 1;
    Hash['O' - 'A'] = 1;
    Hash['T' - 'A'] = 1;
    Hash['U' - 'A'] = 1;
    Hash['V' - 'A'] = 1;
    Hash['W' - 'A'] = 1;
    Hash['X' - 'A'] = 1;
    Hash['Y' - 'A'] = 1;
    scanf("%s", Str);
    Len = strlen(Str);
    for(i = 0; i < Len; ++i)
    {
        if(!Hash[Str[i] - 'A'] || Str[i] != Str[Len - 1 - i])
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
