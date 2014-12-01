#include <stdio.h>

int A[4];

int IsTriangle()
{
    if(A[1] < (A[2] + A[3]) && A[2] < (A[1] + A[3]) && A[3] < (A[1] + A[2]))
    {
        return 1;
    }
    if(A[0] < (A[2] + A[3]) && A[2] < (A[0] + A[3]) && A[3] < (A[0] + A[2]))
    {
        return 1;
    }
    if(A[0] < (A[1] + A[3]) && A[1] < (A[0] + A[3]) && A[3] < (A[0] + A[1]))
    {
        return 1;
    }
    if(A[0] < (A[1] + A[2]) && A[1] < (A[0] + A[2]) && A[2] < (A[0] + A[1]))
    {
        return 1;
    }
    return 0;
}

int IsSegment()
{
    if(A[1] == (A[2] + A[3]) || A[2] == (A[1] + A[3]) || A[3] == (A[1] + A[2]))
    {
        return 1;
    }
    if(A[0] == (A[2] + A[3]) || A[2] == (A[0] + A[3]) || A[3] == (A[0] + A[2]))
    {
        return 1;
    }
    if(A[0] == (A[1] + A[3]) || A[1] == (A[0] + A[3]) || A[3] == (A[0] + A[1]))
    {
        return 1;
    }
    if(A[0] == (A[1] + A[2]) || A[1] == (A[0] + A[2]) || A[2] == (A[0] + A[1]))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    for(i = 0; i < 4; ++i)
    {
        scanf("%d", &A[i]);
    }
    if(IsTriangle())
    {
        puts("TRIANGLE");
    }
    else if(IsSegment())
    {
        puts("SEGMENT");
    }
    else
    {
        puts("IMPOSSIBLE");
    }
    return 0;
}
