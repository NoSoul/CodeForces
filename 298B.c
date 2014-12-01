#include <stdio.h>

int main()
{
    int i, t, sx, sy, ex, ey, tempx, tempy;
    char Str[100001];
    scanf("%d %d %d %d %d %s", &t, &sx, &sy, &ex, &ey, Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        tempx = sx;
        tempy = sy;
        if(Str[i] == 'E')
        {
            ++sx;
        }
        if(Str[i] == 'S')
        {
            --sy;
        }
        if(Str[i] == 'W')
        {
            --sx;
        }
        if(Str[i] == 'N')
        {
            ++sy;
        }
        if((abs(ex - sx) + abs(ey - sy)) > (abs(ex - tempx) + abs(ey - tempy)))
        {
            sx = tempx;
            sy = tempy;
        }
        if(sx == ex && sy == ey)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
