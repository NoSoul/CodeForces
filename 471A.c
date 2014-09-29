#include <stdio.h>

typedef struct
{
    int l;
    int n;
} Sticks_t;
Sticks_t List[6];
int Size;

int main()
{
    int i, j, Num;
    for(i=0; i<6; ++i)
    {
        scanf("%d", &Num);
        for(j=0; j<Size; ++j)
        {
            if(List[j].l == Num)
            {
                ++List[j].n;
                break;
            }
        }
        if(j == Size)
        {
            List[Size].l = Num;
            List[Size++].n = 1;
        }
    }
    for(i=0; i<Size-1; ++i)
    {
        for(j=i+1; j<Size; ++j)
        {
            if(List[i].n < List[j].n)
            {
                Sticks_t temp;
                temp = List[i];
                List[i] = List[j];
                List[j] = temp;
            }
        }
    }
    if(List[0].n < 4)
    {
        puts("Alien");
    }
    else
    {
        List[0].n -= 4;
        int A[2];
        for(i=0,j=0; i<Size; ++i)
        {
            while(List[i].n--)
            {
                A[j++] = List[i].l;
            }
        }
        puts(A[0]==A[1]?"Elephant":"Bear");
    }
    return 0;
}
