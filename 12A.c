#include <stdio.h>

int Check(char Str[][4])
{
    return Str[0][0]==Str[2][2]
           &&Str[0][1]==Str[2][1]
           &&Str[0][2]==Str[2][0]
           &&Str[1][0]==Str[1][2];
}

int main()
{
    int i;
    char Str[4][4];
    for(i=0; i<3; ++i)
    {
        scanf("%s",Str[i]);
    }
    puts(Check(Str)?"YES":"NO");
    return 0;
}
