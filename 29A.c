#include <stdio.h>

typedef struct {
    int m_X;
    int m_D;
} Node_t;
Node_t Data[100];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &Data[i].m_X, &Data[i].m_D);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(Data[j].m_X == Data[i].m_X + Data[i].m_D && Data[j].m_X + Data[j].m_D == Data[i].m_X) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
