#include <stdio.h>

char S[200001];
char T[200001];
int Hash[26][26];
int Ans;
int AnsI, AnsJ;

int main()
{
    int i, j;
    scanf("%*d %s %s", S, T);
    AnsI = AnsJ = -1;
    for(i = 0; S[i] != '\0'; ++i) {
        if(S[i] != T[i]) {
            Hash[S[i] - 'a'][T[i] - 'a'] = i + 1;
            if(Hash[T[i] - 'a'][S[i] - 'a']) {
                Ans = -2;
                AnsI = Hash[T[i] - 'a'][S[i] - 'a'];
                AnsJ = Hash[S[i] - 'a'][T[i] - 'a'];
                break;
            }
        }
    }
    if(AnsI == -1) {
        for(i = 0; S[i] != '\0'; ++i) {
            if(S[i] != T[i]) {
                for(j = 0; j < 26; ++j) {
                    if(Hash[j][S[i] - 'a']) {
                        Ans = -1;
                        AnsI = Hash[j][S[i] - 'a'];
                        AnsJ = Hash[S[i] - 'a'][T[i] - 'a'];
                        break;
                    }
                }
            }
        }
    }
    for(i = 0; S[i] != '\0'; ++i) {
        if(S[i] != T[i]) {
            ++Ans;
        }
    }
    printf("%d\n%d %d\n", Ans, AnsI, AnsJ);
    return 0;
}
