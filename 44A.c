#include <stdio.h>
#include <string.h>

typedef struct {
    char m_Species[11];
    char m_Color[11];
} Leaf;

int main()
{
    int n;
    Leaf ans[100], temp;
    int size = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s %s", temp.m_Species, temp.m_Color);
        int j;
        for(j = 0; j < size; ++j) {
            if(strcmp(temp.m_Species, ans[j].m_Species) == 0 && strcmp(temp.m_Color, ans[j].m_Color) == 0) {
                break;
            }
        }
        if(j == size) {
            ans[size++] = temp;
        }
    }
    printf("%d\n", size);
    return 0;
}
