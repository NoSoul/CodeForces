#include <stdio.h>

typedef struct
{
    int min,max;
} Day_t ;
Day_t Data[30];

int main()
{
    int d,sum,i,Min,Max,temp;
    scanf("%d %d",&d,&sum);
    for(Min=Max=i=0; i<d; ++i)
    {
        scanf("%d %d",&Data[i].min,&Data[i].max);
        Min+=Data[i].min;
        Max+=Data[i].max;
    }
    if(sum<Min||sum>Max)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    sum-=Min;
    for(i=0; i<d; ++i)
    {
        if(sum)
        {
            temp=Data[i].max-Data[i].min;
            if(sum>temp)
            {
                sum-=temp;
                printf("%d ",Data[i].max);
            }
            else
            {
                printf("%d ",Data[i].min+sum);
                sum=0;
            }
        }
        else
        {
            printf("%d ",Data[i].min);
        }
    }
    return 0;
}
