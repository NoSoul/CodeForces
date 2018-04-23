#include <stdio.h>

typedef struct {
    char m_Name[11];
    unsigned m_IP;
} Node_t;
Node_t Data[1000];

unsigned Format(char *str)
{
    unsigned ret = 0;
    unsigned char cur = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == ';') {
            continue;
        }
        if(str[i] == '.') {
            ret <<= 8;
            ret |= cur;
            cur = 0;
        } else {
            cur *= 10;
            cur += str[i] - '0';
        }
    }
    ret <<= 8;
    ret |= cur;
    return ret;
}

int main()
{
    int n, m;
    char temp[16], cmd[11];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s %s", Data[i].m_Name, temp);
        Data[i].m_IP = Format(temp);
    }
    while(m--) {
        scanf("%s %s", cmd, temp);
        unsigned key = Format(temp);
        for(int i = 0; i < n; ++i) {
            if(Data[i].m_IP == key) {
                printf("%s %s #%s\n", cmd, temp, Data[i].m_Name);
                break;
            }
        }
    }
    return 0;
}
