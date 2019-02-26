#include <stdio.h>
#include <string.h>

int Notes(char *str)
{
    char match[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    for(int i = 0; i < 12; ++i) {
        if(strcmp(match[i], str) == 0) {
            return i;
        }
    }
}

int main()
{
    char x[3], y[3], z[3];
    scanf("%s %s %s", x, y, z);
    int noteVal[3];
    noteVal[0] = Notes(x);
    noteVal[1] = Notes(y);
    noteVal[2] = Notes(z);
    for(int i = 0; i < 3; ++i) {
        int k = i;
        for(int j = i + 1; j < 3; ++j) {
            if(noteVal[k] > noteVal[j]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = noteVal[k];
            noteVal[k] = noteVal[i];
            noteVal[i] = temp;
        }
    }
    for(int i = 0; i < 3; ++i) {
        if((noteVal[i] + 4) % 12 == noteVal[(i + 1) % 3] && (noteVal[(i + 1) % 3] + 3) % 12 == noteVal[(i + 2) % 3]) {
            puts("major");
            return 0;
        } else if((noteVal[i] + 3) % 12 == noteVal[(i + 1) % 3] && (noteVal[(i + 1) % 3] + 4) % 12 == noteVal[(i + 2) % 3]) {
            puts("minor");
            return 0;
        }
    }
    puts("strange");
    return 0;
}
