#include <stdio.h>

int main()
{
    char Str[9];
    int i, j;
    int W, B;
    W = B = 0;
    for(i = 0; i < 8; ++i) {
        scanf("%s", Str);
        for(j = 0; Str[j] != '\0'; ++j) {
            if(Str[j] == 'Q') {
                W += 9;
            } else if(Str[j] == 'R') {
                W += 5;
            } else if(Str[j] == 'B') {
                W += 3;
            } else if(Str[j] == 'N') {
                W += 3;
            } else if(Str[j] == 'P') {
                W += 1;
            } else if(Str[j] == 'q') {
                B += 9;
            } else if(Str[j] == 'r') {
                B += 5;
            } else if(Str[j] == 'b') {
                B += 3;
            } else if(Str[j] == 'n') {
                B += 3;
            } else if(Str[j] == 'p') {
                B += 1;
            }
        }
    }
    puts(W > B ? "White" : (W == B ? "Draw" : "Black"));
    return 0;
}
