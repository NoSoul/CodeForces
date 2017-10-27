#include <stdio.h>

int main()
{
    int i, Size;
    char Str[200001];
    char Stack[200001];
    scanf("%*d %s", Str);
    for(i = Size = 0; Str[i] != '\0'; ++i) {
        Stack[Size] = Str[i];
        if(Size >= 1) {
            if(Stack[Size] != Stack[Size - 1]) {
                Size -= 2;
            }
        }
        ++Size;
    }
    printf("%d\n", Size);
    return 0;
}
