#include <stdio.h>

int main()
{
    int i, top = -1;
    char Str[200001];
    char Stack[200001];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        char del = 0;
        if(top >= 0) {
            if(Stack[top] == Str[i]) {
                if(top - 1 >= 0) {
                    if(Stack[top - 1] == Str[i]) {
                        del = 1;
                    } else {
                        if(top - 2 >= 0) {
                            if(Stack[top - 2] == Stack[top - 1]) {
                                del = 1;
                            }
                        }
                    }
                }
            }
        }
        if(!del) {
            Stack[++top] = Str[i];
        }
    }
    Stack[++top] = '\0';
    printf("%s\n", Stack);
    return 0;
}
