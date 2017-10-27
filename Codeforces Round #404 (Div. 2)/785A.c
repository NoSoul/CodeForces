#include <stdio.h>
#include <string.h>

char Str[5][20] = {
    "Tetrahedron",
    "Cube",
    "Octahedron",
    "Dodecahedron",
    "Icosahedron"
};
int Val[5] = {4, 6, 8, 12, 20};

int main()
{
    int n, sum = 0;
    char str[20];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 5; ++j) {
            if(strcmp(Str[j], str) == 0) {
                sum += Val[j];
                break;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
