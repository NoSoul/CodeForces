#include <stdio.h>

int NextH(int h)
{
    if(h == 23)
    {
        return 0;
    }
    return h + 1;
}

int main()
{
    int H, M, temp;
    scanf("%d:%d", &H, &M);
    temp = (H % 10) * 10 + H / 10;
    if(temp > M && temp >= 0 && temp < 60)
    {
        printf("%02d:%02d\n", H, temp);
        return 0;
    }
    while(1)
    {
        H = NextH(H);
        M = (H % 10) * 10 + H / 10;
        if(M >= 0 && M < 60)
        {
            printf("%02d:%02d\n", H, M);
            break;
        }
    }
    return 0;
}
