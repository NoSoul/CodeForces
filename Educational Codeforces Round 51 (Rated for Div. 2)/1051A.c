#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        char s[101];
        scanf("%s", s);
        unsigned uCnt, lCnt, dCnt;
        uCnt = lCnt = dCnt = 0;
        for(int i = 0; s[i]; ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                ++uCnt;
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                ++lCnt;
            } else {
                ++dCnt;
            }
        }
        if(uCnt == 0 && lCnt != 0 && dCnt != 0) {
            if(lCnt > dCnt) {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= 'a' && s[i] <= 'z') {
                        s[i] = 'A';
                        break;
                    }
                }
            } else {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= '0' && s[i] <= '9') {
                        s[i] = 'A';
                        break;
                    }
                }
            }
        } else if(uCnt != 0 && lCnt == 0 && dCnt != 0) {
            if(uCnt > dCnt) {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= 'A' && s[i] <= 'Z') {
                        s[i] = 'a';
                        break;
                    }
                }
            } else {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= '0' && s[i] <= '9') {
                        s[i] = 'a';
                        break;
                    }
                }
            }
        } else if(uCnt != 0 && lCnt != 0 && dCnt == 0) {
            if(uCnt > lCnt) {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= 'A' && s[i] <= 'Z') {
                        s[i] = '0';
                        break;
                    }
                }
            } else {
                for(int i = 0; s[i]; ++i) {
                    if(s[i] >= 'a' && s[i] <= 'z') {
                        s[i] = '0';
                        break;
                    }
                }
            }
        } else if(uCnt == strlen(s)) {
            s[0] = 'a';
            s[1] = '0';
        } else if(lCnt == strlen(s)) {
            s[0] = 'A';
            s[1] = '0';
        } else if(dCnt == strlen(s)) {
            s[0] = 'a';
            s[1] = 'A';
        }
        puts(s);
    }
    return 0;
}
