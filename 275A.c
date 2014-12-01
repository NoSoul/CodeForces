#include <stdio.h>

char Str[9][10] =
{
    "110100000",
    "111010000",
    "011001000",
    "100110100",
    "010111010",
    "001011001",
    "000100110",
    "000010111",
    "000001011"
};

int main()
{
    int i, j, k, index;
    int Mat[3][3];
    char Res[10] = "111111111";
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            scanf("%d", &Mat[i][j]);
            if(Mat[i][j] & 1)
            {
                index = i * 3 + j;
                for(k = 0; k < 9; ++k)
                {
                    if(Str[index][k] == '1')
                    {
                        Res[k] = (Res[k] == '0') ? '1' : '0';
                    }
                }
            }
        }
    }
    printf("%c%c%c\n", Res[0], Res[1], Res[2]);
    printf("%c%c%c\n", Res[3], Res[4], Res[5]);
    printf("%c%c%c\n", Res[6], Res[7], Res[8]);
    return 0;
}
